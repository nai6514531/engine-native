/****************************************************************************
 Copyright (c) 2019-2021 Xiamen Yaji Software Co., Ltd.

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

#include "../core/CoreStd.h"
#include "Define.h"
#include "helper/DefineMap.h"
#include "helper/SharedMemory.h"
#include "PipelineUBO.h"
#include "PipelineSceneData.h"

namespace cc {
namespace gfx {
class CommandBuffer;
class DescriptorSet;
class DescriptorSetLayout;
struct Camera;
} // namespace gfx
namespace pipeline {
class DefineMap;

struct CC_DLL RenderPipelineInfo {
    uint tag = 0;
    RenderFlowList flows;
};

class CC_DLL RenderPipeline : public Object {
public:
    static RenderPipeline *getInstance();

    RenderPipeline();
    virtual ~RenderPipeline();

    virtual bool activate();
    virtual void destroy();
    virtual bool initialize(const RenderPipelineInfo &info);
    virtual void render(const vector<uint> &cameras);

    void setPipelineSharedSceneData(uint handle);

    CC_INLINE const RenderFlowList &getFlows() const { return _flows; }
    CC_INLINE uint getTag() const { return _tag; }
    CC_INLINE const map<String, InternalBindingInst> &getGlobalBindings() const { return _globalBindings; }
    CC_INLINE const DefineMap &getMacros() const { return _macros; }
    CC_INLINE void setValue(const String &name, bool value) { _macros.setValue(name, value); }
    CC_INLINE gfx::DescriptorSet *getDescriptorSet() const { return _descriptorSet; }
    CC_INLINE gfx::DescriptorSetLayout *getDescriptorSetLayout() const { return _descriptorSetLayout; }
    CC_INLINE gfx::Texture *getDefaultTexture() const { return _defaultTexture; }
    CC_INLINE PipelineSceneData *getPipelineSceneData() const { return _pipelineSceneData; }
    CC_INLINE const gfx::CommandBufferList &getCommandBuffers() const { return _commandBuffers; }
    CC_INLINE PipelineUBO *getPipelineUBO() const { return _pipelineUBO; }
    CC_INLINE gfx::Device *getDevice() { return _device; }

protected:
    static RenderPipeline *_instance;
    void setDescriptorSetLayout();

    gfx::CommandBufferList _commandBuffers;
    RenderFlowList _flows;
    map<String, InternalBindingInst> _globalBindings;
    DefineMap _macros;
    uint _tag = 0;

    gfx::Device *_device = nullptr;
    gfx::DescriptorSetLayout *_descriptorSetLayout = nullptr;
    gfx::DescriptorSet *_descriptorSet = nullptr;
    PipelineUBO *_pipelineUBO = nullptr;
    PipelineSceneData *_pipelineSceneData = nullptr;
    // has not initBuiltinRes,
    // create temporary default Texture to binding sampler2d
    gfx::Texture *_defaultTexture = nullptr;
};

} // namespace pipeline
} // namespace cc
