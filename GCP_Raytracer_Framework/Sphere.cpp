#include "Sphere.h"

Sphere::Sphere()
{
	position = glm::vec3{ 320,240,-50 };
	radius = 5.0f;
}

Sphere::~Sphere()
{
}

bool Sphere::RayIntersect(Ray _ray)
{
	Sphere s;

	glm::vec3 a = _ray.origin;
	glm::vec3 n = _ray.direction;
	glm::vec3 p = s.position;
	float r = s.radius;


	float d = glm::length(p - a - dot((p - a), n)*n);
	float x = sqrt(pow(r, 2) - pow(d, 2));

	return d < 0;
}

glm::vec3 Sphere::Shade(glm::vec3 _intersectPoint)
{
	return glm::vec3();
}

glm::vec3 Sphere::GetNormal(glm::vec3 _point)
{
	return glm::vec3();
}
