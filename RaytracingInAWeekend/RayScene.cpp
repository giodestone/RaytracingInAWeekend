#include "RayScene.h"

void RayScene::OnInit()
{
	renderTexture = std::make_unique<Image>(GetApp().get(), App::windowWidth, App::windowHeight);
}

void RayScene::OnLoop()
{
}

void RayScene::OnRender()
{
	SDL_RenderCopy(GetApp().get().Renderer(), renderTexture->GetTexture(), nullptr, nullptr);
}
