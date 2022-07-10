import numpy as np


class Sphere(object):
    def __init__(self, center, radius):
        """Instantiate a sphere.

        Args:
            center (numpy.ndarray): A 3-D vector, represents the center of the sphere.
            radius (float): The radius of the sphere.
        """
        self.center = center
        self.radius = radius


class Ray(object):
    def __init__(self, origin, direction):
        """Instantiate a ray.
        A ray has an origin and a direction, points on the ray can be
        parameterized as: origin + t * direction (t>=0). t means how
        long the point travels along the ray's direction.

        Args:
            origin (numpy.ndarray): A 3-D vector, represents the start point of the ray.
            direction (numpy.ndarray): A 3-D vector, represents the direction of the ray.
        """
        self.origin = origin
        self.direction = direction


# You are asked to implement the function ray_sphere_intersect:
def ray_sphere_intersect(ray, sphere):
    """Calculate the intersection point of a ray and a sphere.

    Args:
            ray (Ray): A ray object.
            sphere (Sphere): A sphere object.

    Returns:
            numpy.ndarray: A 3-D vector, represents the intersection point of the ray and the sphere.
    """
    # distance between the ray and the sphere's center
    point1 = ray.origin
    point2 = ray.origin + ray.direction
    # cross
    cros = np.cross(point1 - sphere.center, point2 - sphere.center)
    mlen = np.linalg.norm(point2 - point1)
    distance = np.linalg.norm(point2 - point1) / (mlen * mlen)
    if distance > sphere.radius:
        return None
    else:
        half_chord = np.sqrt(sphere.radius * sphere.radius - distance * distance)
        dist_origin = np.linalg.norm(ray.origin - sphere.center)
        l = (
            np.sqrt(dist_origin * dist_origin - sphere.radius * sphere.radius)
            - half_chord
        )
        t = l / mlen
        point_int = ray.origin + t * ray.direction
        if np.linalg.norm(point_int - sphere.center) > sphere.radius:
            return None
        else:
            return point_int


###################
# Below are tests #
###################
# This should give 1.0
print(
    ray_sphere_intersect(
        Ray(np.array([0, 0, 0]), np.array([1, 0, 0])), Sphere(np.array([2, 0, 0]), 1)
    )
)
# This should give None
print(
    ray_sphere_intersect(
        Ray(np.array([0, 0, 0]), np.array([1, 0, 0])), Sphere(np.array([-2, 0, 0]), 1)
    )
)
# This should give 2.0
print(
    ray_sphere_intersect(
        Ray(np.array([0, 0, 0]), np.array([1, 0, 0])), Sphere(np.array([0, 0, 0]), 2)
    )
)
# This should give None
print(
    ray_sphere_intersect(
        Ray(np.array([0, 0, 0]), np.array([1, 1, 0])), Sphere(np.array([2, 0, 0]), 1)
    )
)
