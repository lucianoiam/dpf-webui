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

#ifndef CEF_MESSAGE_THREAD_HPP
#define CEF_MESSAGE_THREAD_HPP

#include "extra/Thread.hpp"
#include "extra/Mutex.hpp"
#include "CefMain.hpp"

START_NAMESPACE_DISTRHO

class CefMessageThread : public Thread
{
public:
    CefMessageThread() : Thread("shared_cef") {};
    ~CefMessageThread() {};

    void run() override;

    void waitForInit();

    CefRefPtr<CefMain> getCefMain();

private:
    CefRefPtr<CefMain> mMain;

    Signal        mCefInitSignal;
    volatile bool mCefInit;

};

END_NAMESPACE_DISTRHO

#endif // CEF_MESSAGE_THREAD_HPP
