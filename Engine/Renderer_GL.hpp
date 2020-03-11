#pragma once
#include "Renderer.hpp"
#include <GL/glew.h>

enum GLRenderPasses
{
	RenderPass_UI,
	RenderPass_Text,
	RenderPass_NumRenderPasses,
};

/**
 *	Generic OpenGL render objects only contain an EBO and a VAO.
 *	VAOs hold our VBOs which have our vertices in them.
 */
class GLRenderObject : public IRenderObject
{
protected:
	BYTE palshift;
	float screenCoord[4]; // x y w h
	float textureCoord[4]; //x y w h (normalized)
	float colorModulate[4]; //r g b a (normalized)
	int drawMode;

	enum
	{
		RO_Static,
		RO_Animated,
		RO_Text,
	} objectType;

	union
	{
		struct
		{
			uint64_t lastFrameTime;
			uint16_t currentFrame;
			uint16_t numFrames;
			uint32_t frameRate;
			class IGraphicsHandle* attachedAnimationResource;
		} animationData;

		struct
		{
			class IGraphicsHandle* attachedFontResource;
			char16_t text[128];
		} textData;
	} data;

public:
	unsigned int texture;

	GLRenderPasses renderPass;

	GLRenderObject();
	~GLRenderObject();

	bool bInUse;

	virtual void Draw();
	virtual void Render();	// Internal rendering function, used by the renderer itself.
	virtual void SetPalshift(BYTE palette);
	virtual void SetDrawCoords(int x, int y, int w, int h);
	virtual void GetDrawCoords(int* x, int* y, int* w, int* h);
	void SetWidthHeight(int w, int h);

	virtual void AttachTextureResource(class IGraphicsHandle* handle, int32_t frame);
	virtual void AttachCompositeTextureResource(class IGraphicsHandle* handle, int32_t startFrame, int32_t endFrame);
	virtual void AttachPaletteResource(class IGraphicsHandle* handle);
	virtual void AttachAnimationResource(class IGraphicsHandle* handle);
	virtual void AttachTokenResource(class IGraphicsHandle* handle);
	virtual void AttachFontResource(class IGraphicsHandle* handle);

	virtual void SetFramerate(int framerate);
	virtual void SetDrawMode(int drawMode);
	virtual void SetText(const char16_t* text);
	virtual void SetColorModulate(float r, float g, float b, float a);
};

/**
 *	Memory pool
 */
class GLRenderPool
{
	void* MemoryPool;
	size_t remaining;
	size_t elementsRemaining;
	size_t initial;

	GLRenderPool* next;
	GLRenderObject* head;
public:
	GLRenderPool(size_t initialSize);
	~GLRenderPool();

	GLRenderObject* Allocate();
	void Deallocate(GLRenderObject* object);
};

/**
 * OpenGL renderer
 */
class Renderer_GL : public IRenderer
{
private:
	SDL_GLContext context;
	SDL_Window* targetWindow;

	static void LoadShaderText(const char* shaderText, unsigned int& shader, unsigned int shaderType);
	static void LoadProgram(const char* shaderFile, unsigned int& program, void(*fallbackIfNotFound)(unsigned int &program, const char *programFile));
	static void SaveProgram(unsigned int program, const char* shaderFile);
	static void LinkProgram(unsigned int program, const char* programName);
	static void InitShaders();
	static void DeleteShaders();

	GLRenderPool* pool;
	BYTE defaultPalshift[256];

	unsigned int VAO, VBO;
public:
	virtual void Present();
	virtual void Clear();
	virtual void SetGlobalPalette(const D2Palettes palette);

	virtual IRenderObject* AllocateObject(int stage);
	virtual void Remove(IRenderObject* Object);

	Renderer_GL(D2GameConfigStrc* pConfig, OpenD2ConfigStrc* pOpenConfig, SDL_Window* pWindow);
	~Renderer_GL();

	void AddToRenderQueue(class GLRenderObject* Object);
};
