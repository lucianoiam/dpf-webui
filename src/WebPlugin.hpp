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

#ifndef WEBPLUGIN_HPP
#define WEBPLUGIN_HPP

#include "DistrhoPlugin.hpp"

START_NAMESPACE_DISTRHO

class WebPlugin : public Plugin
{
public:
    WebPlugin();
    ~WebPlugin();

    const char* getLabel() const
    {
        return "Web UI Example";
    }

    const char* getMaker() const
    {
        return "Luciano Iam";
    }

    const char* getLicense() const
    {
        return "ISC";
    }

    uint32_t getVersion() const
    {
        return 0;
    }

    int64_t getUniqueId() const override
    {
        return d_cconst('d', 'W', 'e', 'b');
    }

    void  initParameter(uint32_t index, Parameter& parameter);
    float getParameterValue(uint32_t index) const;
    void  setParameterValue(uint32_t index, float value);

    void run(const float** inputs, float** outputs, uint32_t frames);

};

END_NAMESPACE_DISTRHO

#endif  // WEBPLUGIN_HPP
