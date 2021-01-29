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

#include <syslog.h>

USE_NAMESPACE_DISTRHO

BrowserFactory::BrowserFactory()
{
    syslog(LOG_INFO, "%p BrowserFactory::BrowserFactory()", this);

    // mCefThread initializes, shutdowns and runs CEF message loop.
    // CEF cannot be initialized and uninintialized multiple times during the
    // process lifetime ( FIXME : insert link )

    // Single BrowserFactory is a singleton, first plugin instance inits CEF
    mCefThread.startThread();

    // Block until CEF is completely initialized
    mCefThread.waitForInit();
}

BrowserFactory::~BrowserFactory()
{
    syslog(LOG_INFO, "%p BrowserFactory::~BrowserFactory()", this);

    // FIXME -- CefQuitMessageLoop() does not appear to do anything
    //CefQuitMessageLoop();

    mCefThread.stopThread(100);
}

void BrowserFactory::createBrowser(uintptr_t parentWindowId)
{
    syslog(LOG_INFO, "%p BrowserFactory::createBrowser() parentWindowId = %p",
        this, (void*)parentWindowId);

    mCefThread.getCefMain()->createBrowser(parentWindowId);
}

void BrowserFactory::destroyBrowser(uintptr_t parentWindowId)
{
    syslog(LOG_INFO, "%p BrowserFactory::destroyBrowser() parentWindowId = %p",
        this, (void*)parentWindowId);

    mCefThread.getCefMain()->getBrowserHandler()->getBrowser(parentWindowId)
        ->GetHost()->CloseBrowser(true);
}

BrowserFactory& BrowserFactory::getInstance()
{
    static BrowserFactory instance;
    return instance;
}
