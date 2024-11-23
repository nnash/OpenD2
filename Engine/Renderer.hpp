#pragma once
// #include "Diablo2.hpp"
#include "../Shared/D2Shared.hpp"
#include <SDL.h>

// The render targets
enum OpenD2RenderTargets
{
	OD2RT_SDL,			// SDL renderer with hardware acceleration (default for now)
	OD2RT_OPENGL,		// OpenGL
	OD2RT_MAX
};

// Renderer.cpp
namespace Renderer
{
	void Init(D2GameConfigStrc* pConfig, OpenD2ConfigStrc* pOpenConfig, SDL_Window* pWindow);
	void MapRenderTargetExports(D2ModuleImportStrc* pExport);
}

extern class IRenderer* RenderTarget;	// nullptr if there isn't a render target
