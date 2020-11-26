#include "GameObjectComponent.h"

our::GameObjectComponent()
{
	Enabled = true;
	gameObject = nullptr;
}

virtual void Start() //Called once per component
{

}

virtual void Update(double deltaTime)  //Called every frame
{

}

virtual void Draw()  //Called every frame after "Update()" execution
{

}

virtual void Destroy()
{
	gameObject.RemoveComponent<GameObjectComponent>(this);
	Destroy();
}

~GameObjectComponent()
{
	Destroy();
}

/*virtual GameObjectComponent DeepCopy(GameObject Clone)
{
	return this() as GameObjectComponent;
}*/