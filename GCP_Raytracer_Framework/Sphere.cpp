#include "Sphere.h"

Sphere::Sphere()
{
	position = glm::vec3{ 320,240,-50 };
	radius = 50.0f;
	matColour = glm::vec3{ 0.f,0.f,1.0f };

	lightSource = glm::normalize(glm::vec3{ 2.0,1.0,2.0 });
}

Sphere::~Sphere()
{
}

RayInfo Sphere::RayIntersect(Ray _ray)
{	
	RayInfo rF;

	glm::vec3 a = _ray.origin;
	glm::vec3 n = _ray.direction;
	glm::vec3 p = position;
	float r = radius;



	float d = glm::length(p - a - dot((p - a), n)*n);
	float x = sqrt(pow(r, 2) - pow(d, 2));

	//getting the normal
	glm::vec3 iP = a + (glm::dot((p - a), n) - x) * n;

	rF.intersect = d < r;
	rF.iP = iP;

	return rF;
}

glm::vec3 Sphere::Shade(glm::vec3 _intersectPoint)
{
	//building the colour
	glm::vec3 surfaceNormal = GetNormal(_intersectPoint);

	//diffuse lighting equation
	glm::vec3 lightColour = glm::dot(lightSource, surfaceNormal) * matColour;
	return lightColour;

	//introducing the shininess and refraction.
}

glm::vec3 Sphere::GetNormal(glm::vec3 _point)
{
	return glm::normalize(_point - position);
}
