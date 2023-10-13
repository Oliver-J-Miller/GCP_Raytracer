#include "Ray_Tracer.h"

RayTracer::RayTracer()
{
	Sphere s;
	objects.push_back(&s);
}

RayTracer::~RayTracer()
{
}

glm::vec3 RayTracer::TraceRay(Ray _ray)
{
	bool intersect;
	intersect = objects[0]->RayIntersect(_ray);
	if (intersect == false)
	{
		return glm::vec3(0.0, 0.0, 0.0);
	}
	return glm::vec3(0.0,0.0,1.0);
}

