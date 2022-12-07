#pragma once
#include "Canvas.h"
#include "../Math/Ray.h"
#include "../Objects/Sphere.h"
#include <SDL.h>

class Object;
class Scene;

class Renderer
{
public:
	Renderer() = default;

	bool Initialize();
	void Shutdown();
	bool CreateWindow(int width, int height);

	void CopyCanvas(const Canvas& canvas);
	void Present();

	void Render(Canvas& canvas, Scene& scene);

	friend class Canvas;

private:
	color3 GetBackgroundFromRay(const Ray& ray);

private:
	SDL_Window* m_window{ nullptr };
	SDL_Renderer* m_renderer{ nullptr };
	
};