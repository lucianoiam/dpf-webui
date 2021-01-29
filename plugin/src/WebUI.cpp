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

#include "WebUI.hpp"
#include "Window.hpp"
//#include "BrowserFactory.hpp"

#include <syslog.h>

USE_NAMESPACE_DISTRHO

UI* DISTRHO::createUI()
{
    return new WebUI;
}

WebUI::WebUI()
    : UI(800, 600)
{
    syslog(LOG_INFO, "%p WebUI::WebUI()", this);

    // TODO : some hosts like REAPER recreate the parent window every time
    //        the plugin UI is opened

    // UI and DSP code are completely isolated, pass opaque pointer as the owner
    //uintptr_t parentWindowId = getParentWindow().getWindowId();
    //BrowserFactory::getInstance().createBrowser(parentWindowId);
}

WebUI::~WebUI()
{
    syslog(LOG_INFO, "%p WebUI::~WebUI()", this);

    //uintptr_t parentWindowId = getParentWindow().getWindowId();
    //BrowserFactory::getInstance().destroyBrowser(parentWindowId);
}

void WebUI::onDisplay()
{
    syslog(LOG_INFO, "%p WebUI::onDisplay()", this);
}

void WebUI::parameterChanged(uint32_t index, float value)
{
    // unused
    (void)index;
    (void)value;
}
