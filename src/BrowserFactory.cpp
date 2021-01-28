/*
 * dpf-webui
 * Copyright (C) 2021 Luciano Iam <lucianoiam@protonmail.com>
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

#include "BrowserFactory.hpp"

USE_NAMESPACE_DISTRHO

BrowserFactory::BrowserFactory()
{
    // CEF cannot be initialized and un-inintialized multiple times during
    // the process lifetime ( FIXME : insert link )

    mCefThread.startThread();
}

BrowserFactory::~BrowserFactory()
{
    mCefThread.stopThread(1000);

    // TODO -- code and comments from earlier versions

    // mBrowserHandler becomes null, check memory mgmt
    /*if (mMain->getBrowserHandler()) {
        mMain->getBrowserHandler()->getBrowserInstance()->GetHost()->CloseBrowser(false);
    }*/

    /*
        sCefThread.stopThread(1000);

        // Since the CEF window is a child of the DPF window, need to explicity
        // tell the browser to close. That will in turn call CefQuitMessageLoop()
        // effectively ending the CefMessageThread
        // https://bitbucket.org/chromiumembedded/cef/wiki/GeneralUsage#markdown-header-browser-life-span
        //mCefThread.closeBrowser();

        // Wait until CefQuitMessageLoop() is called
        //mCefThread.stopThread(1000);
    */
}

void BrowserFactory::createBrowser(void *owner, uintptr_t parentWindowId)
{
    mCefThread.waitForInit();

    mCefThread.getCefMain()->waitForInit();
    mCefThread.getCefMain()->createBrowser(parentWindowId);
}

void BrowserFactory::destroyBrowser(void *owner)
{
    // TO DO
}

BrowserFactory& BrowserFactory::getInstance()
{
    static BrowserFactory instance;
    return instance;
}
