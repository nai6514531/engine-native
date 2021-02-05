/****************************************************************************
 Copyright (c) 2017-2021 Xiamen Yaji Software Co., Ltd.

 http://www.cocos.com

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated engine source code (the "Software"), a limited,
 worldwide, royalty-free, non-assignable, revocable and non-exclusive license
 to use Cocos Creator solely to develop games on your target platforms. You shall
 not use Cocos Creator software for developing other software or tools that's
 used for developing games. You are not granted to publish, distribute,
 sublicense, and/or sell copies of Cocos Creator.

 The software or tools in this License Agreement are licensed, not sold.
 Xiamen Yaji Software Co., Ltd. reserves all rights not expressly granted to you.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
****************************************************************************/

#pragma once

#include "cocos/bindings/jswrapper/SeApi.h"
#include "cocos/network/WebSocket.h"

namespace se {
class Object;
class Value;
} // namespace se

class JSB_WebSocketDelegate : public cc::Ref, public cc::network::WebSocket::Delegate {
public:
    JSB_WebSocketDelegate();

    virtual void onOpen(cc::network::WebSocket *ws) override;

    virtual void onMessage(cc::network::WebSocket *ws,
                           const cc::network::WebSocket::Data &data) override;

    virtual void onClose(cc::network::WebSocket *ws) override;

    virtual void onError(cc::network::WebSocket *ws,
                         const cc::network::WebSocket::ErrorCode &error) override;

    void setJSDelegate(const se::Value &jsDelegate);

private:
    virtual ~JSB_WebSocketDelegate();

    se::Value _JSDelegate;
};

SE_DECLARE_FINALIZE_FUNC(WebSocket_finalize);

SE_DECLARE_FUNC(WebSocket_constructor);

SE_DECLARE_FUNC(WebSocket_send);

SE_DECLARE_FUNC(WebSocket_close);

bool register_all_websocket(se::Object *obj);
