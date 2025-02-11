/*
 * Copyright (c) 2020, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/ByteBuffer.h>
#include <AK/Error.h>
#include <AK/String.h>
#include <AK/StringView.h>

namespace AK {

[[nodiscard]] size_t calculate_base64_decoded_length(StringView);

[[nodiscard]] size_t calculate_base64_encoded_length(ReadonlyBytes);

[[nodiscard]] ErrorOr<ByteBuffer> decode_base64(StringView);

[[nodiscard]] ErrorOr<ByteBuffer> decode_forgiving_base64(StringView);

[[nodiscard]] ErrorOr<String> encode_base64(ReadonlyBytes);
}

#if USING_AK_GLOBALLY
using AK::decode_base64;
using AK::encode_base64;
#endif
