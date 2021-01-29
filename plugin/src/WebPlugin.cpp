/*
 * dpf-webui
 * Copyright (C) 2021 Luciano Iam <lucianoiam@protonmail.com>
 *
 * DISTRHO Plugin Framework (DPF)
 * Copyright (C) 2012-2019 Filipe Coelho <falktx@falktx.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any purpose with
 * or without fee is hereby granted, provided that the above copyright notice and this
 * permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD
 * TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN
 * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "WebPlugin.hpp"

#include <syslog.h>

USE_NAMESPACE_DISTRHO

Plugin* DISTRHO::createPlugin()
{
    return new WebPlugin;
}

WebPlugin::WebPlugin()
    : Plugin(0, 0, 0)
{
    syslog(LOG_INFO, "%p WebPlugin::WebPlugin()", this);
}

WebPlugin::~WebPlugin()
{
    syslog(LOG_INFO, "%p WebPlugin::~WebPlugin()", this);
}

void WebPlugin::initParameter(uint32_t index, Parameter& parameter)
{
    // unused
    (void)index;
    (void)parameter;
}

float WebPlugin::getParameterValue(uint32_t index) const
{
    return 0;

    // unused
    (void)index;
}

void WebPlugin::setParameterValue(uint32_t index, float value)
{
    // unused
    (void)index;
    (void)value;
}

void WebPlugin::run(const float** inputs, float** outputs, uint32_t frames)
{
    memcpy(outputs[0], inputs[0], frames * sizeof(float));
}
