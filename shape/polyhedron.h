#ifndef MODULE_GRAPHICS_GEOMETRY_POLYHEDRON_H_
#define MODULE_GRAPHICS_GEOMETRY_POLYHEDRON_H_

#include <vector>
#include "../geometry/plane.h"
#include "shape.h"

namespace Shape {

    class Polyhedron : public Shape {

        std::vector<Geometry::Plane> planes;

    public:

        Polyhedron (const std::vector<Geometry::Plane> &_planes) :
            planes(_planes) {}

        const std::vector<Geometry::Plane> &getPlanes (void) const { return this->planes; }

        void addPlane (const Geometry::Plane &plane) { this->planes.push_back(plane); }
        void popPlane (void) { this->planes.pop_back(); }

        inline bool fit (void) const override { return true; }

        inline const Shape *boundingVolume (void) const override { return this; }

        const char *getType (void) const override { return "polyhedron"; }

        inline Shape *clone (void) const override { return new Polyhedron(this->getPlanes()); }

        bool intersectLine (const Geometry::Line &line, Geometry::Vec<3> &normal_min, Geometry::Vec<3> &normal_max, float_max_t &t_min, float_max_t &t_max, bool fix_normals = true) const override;

    };

};

#endif