/*
 * Copyright (c) 2020-2022, Linus Groh <linusg@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/TypedArrayConstructor.h>

namespace JS {

TypedArrayConstructor::TypedArrayConstructor(FlyString const& name, Object& prototype)
    : NativeFunction(name, prototype)
{
}

TypedArrayConstructor::TypedArrayConstructor(Realm& realm)
    : NativeFunction(realm.vm().names.TypedArray.as_string(), *realm.intrinsics().function_prototype())
{
}

void TypedArrayConstructor::initialize(Realm& realm)
{
    auto& vm = this->vm();
    NativeFunction::initialize(realm);

    // 23.2.2.3 %TypedArray%.prototype, https://tc39.es/ecma262/#sec-%typedarray%.prototype
    define_direct_property(vm.names.prototype, realm.intrinsics().typed_array_prototype(), 0);

    u8 attr = Attribute::Writable | Attribute::Configurable;
    define_native_function(realm, vm.names.from, from, 1, attr);
    define_native_function(realm, vm.names.of, of, 0, attr);

    define_native_accessor(realm, *vm.well_known_symbol_species(), symbol_species_getter, {}, Attribute::Configurable);

    define_direct_property(vm.names.length, Value(0), Attribute::Configurable);
}

// 23.2.1.1 %TypedArray% ( ), https://tc39.es/ecma262/#sec-%typedarray%
ThrowCompletionOr<Value> TypedArrayConstructor::call()
{
    return TRY(construct(*this));
}

// 23.2.1.1 %TypedArray% ( ), https://tc39.es/ecma262/#sec-%typedarray%
ThrowCompletionOr<NonnullGCPtr<Object>> TypedArrayConstructor::construct(FunctionObject&)
{
    return vm().throw_completion<TypeError>(ErrorType::ClassIsAbstract, "TypedArray");
}

// 23.2.2.1 %TypedArray%.from ( source [ , mapfn [ , thisArg ] ] ), https://tc39.es/ecma262/#sec-%typedarray%.from
JS_DEFINE_NATIVE_FUNCTION(TypedArrayConstructor::from)
{
    auto constructor = vm.this_value();
    if (!constructor.is_constructor())
        return vm.throw_completion<TypeError>(ErrorType::NotAConstructor, constructor.to_string_without_side_effects());

    FunctionObject* map_fn = nullptr;
    if (!vm.argument(1).is_undefined()) {
        auto callback = vm.argument(1);
        if (!callback.is_function())
            return vm.throw_completion<TypeError>(ErrorType::NotAFunction, callback.to_string_without_side_effects());
        map_fn = &callback.as_function();
    }

    auto source = vm.argument(0);
    auto this_arg = vm.argument(2);

    auto using_iterator = TRY(source.get_method(vm, *vm.well_known_symbol_iterator()));
    if (using_iterator) {
        auto values = TRY(iterable_to_list(vm, source, using_iterator));

        MarkedVector<Value> arguments(vm.heap());
        arguments.empend(values.size());
        auto target_object = TRY(typed_array_create(vm, constructor.as_function(), move(arguments)));

        for (size_t k = 0; k < values.size(); ++k) {
            auto k_value = values[k];
            Value mapped_value;
            if (map_fn)
                mapped_value = TRY(JS::call(vm, *map_fn, this_arg, k_value, Value(k)));
            else
                mapped_value = k_value;
            TRY(target_object->set(k, mapped_value, Object::ShouldThrowExceptions::Yes));
        }

        return target_object;
    }

    auto array_like = MUST(source.to_object(vm));
    auto length = TRY(length_of_array_like(vm, *array_like));

    MarkedVector<Value> arguments(vm.heap());
    arguments.empend(length);
    auto target_object = TRY(typed_array_create(vm, constructor.as_function(), move(arguments)));

    for (size_t k = 0; k < length; ++k) {
        auto k_value = TRY(array_like->get(k));
        Value mapped_value;
        if (map_fn)
            mapped_value = TRY(JS::call(vm, *map_fn, this_arg, k_value, Value(k)));
        else
            mapped_value = k_value;
        TRY(target_object->set(k, mapped_value, Object::ShouldThrowExceptions::Yes));
    }

    return target_object;
}

// 23.2.2.2 %TypedArray%.of ( ...items ), https://tc39.es/ecma262/#sec-%typedarray%.of
JS_DEFINE_NATIVE_FUNCTION(TypedArrayConstructor::of)
{
    auto length = vm.argument_count();
    auto constructor = vm.this_value();
    if (!constructor.is_constructor())
        return vm.throw_completion<TypeError>(ErrorType::NotAConstructor, constructor.to_string_without_side_effects());
    MarkedVector<Value> arguments(vm.heap());
    arguments.append(Value(length));
    auto new_object = TRY(typed_array_create(vm, constructor.as_function(), move(arguments)));
    for (size_t k = 0; k < length; ++k)
        TRY(new_object->set(k, vm.argument(k), Object::ShouldThrowExceptions::Yes));
    return new_object;
}

// 23.2.2.4 get %TypedArray% [ @@species ], https://tc39.es/ecma262/#sec-get-%typedarray%-@@species
JS_DEFINE_NATIVE_FUNCTION(TypedArrayConstructor::symbol_species_getter)
{
    return vm.this_value();
}

}
