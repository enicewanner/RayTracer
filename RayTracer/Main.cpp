#include "Renderer/Renderer.h"
#include "Objects/Sphere.h"
#include "Objects/Scene.h"
#include <iostream>
#include <memory>

int main(int, char**)
{
	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow(1200, 600);

	Canvas canvas(400, 300, renderer);
	Scene scene;

	//auto sphere = std::make_unique<Sphere>(glm::vec3{ 0, 0, 1 }, 0.5f, nullptr);
	//auto sphere = std::make_unique<Sphere>(glm::vec3{ 0, 0, 1 }, 0.5f, std::make_unique<Lambertian>(color3{0, 1, 0}, ));
	scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 0, 0, -1 }, 0.5f, std::make_unique<Lambertian>(color3{0, 1, 0} )));
	scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 0, -100.5f, -1 }, 100.0f, std::make_unique<Lambertian>(color3{0.2, 0.2, 0.2})));


	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				quit = true;
				break;
			}
			break;
		}

		//renderer scene
		canvas.Clear({0.7, 0, 0, 1});
		renderer.Render(canvas, scene);
		canvas.Update();
		//for (int i = 0; i < 5000; i++)
		//{
		//canvas.DrawPoint({ 300, 200 }, { 1, 0, 0, 1 });

		//}

		renderer.CopyCanvas(canvas);
		renderer.Present();

	}
	renderer.Shutdown();
	return 0;	

}
