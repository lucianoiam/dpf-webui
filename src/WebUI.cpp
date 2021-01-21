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

#include "DistrhoUI.hpp"
#include "Window.hpp"
#include "WebEngineThread.hpp"

START_NAMESPACE_DISTRHO

class WebExampleUI : public UI
{
public:
    WebExampleUI()
        : UI(800, 600)
    {
        // This is just a proof of concept, lifecycle of this needs work
        
        auto engine = new WebEngineThread(getParentWindow().getWindowId());
        engine->startThread();

        // Also some hosts like REAPER recreate the parent window every time
        // the plugin UI is opened, we might let CEF create its own window
        // then reparent as needed -- possibly in onDisplay() ?
    }

    ~WebExampleUI()
    {
    }

    void onDisplay()
    {
        // TODO
    }

    void parameterChanged(uint32_t index, float value)
    {
        // unused
        (void)index;
        (void)value;
    }

};

UI* createUI()
{
    return new WebExampleUI;
}

END_NAMESPACE_DISTRHO
