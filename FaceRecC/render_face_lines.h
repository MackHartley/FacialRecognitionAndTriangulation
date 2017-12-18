// Copyright (C) 2014  Davis E. King (davis@dlib.net)
// License: Boost Software License   See LICENSE.txt for the full license.
#ifndef DLIB_RENDER_FACE_LINES_H_
#define DLIB_RENDER_FACE_LINES_H_

#include "dlib/image_processing/full_object_detection.h"
#include "dlib/gui_widgets.h"
#include "dlib/image_processing/render_face_detections_abstract.h"
#include <vector>
#include <list>
#include "delaunay-triangulation/delaunay.h"
#include "delaunay-triangulation/vector2.h"
#include "delaunay-triangulation/triangle.h"
#include "dlib/geometry/vector.h"


typedef dlib::point myPoint;


namespace dlib
{
    inline std::vector<image_window::overlay_line> render_face_lines (
            const std::vector<full_object_detection>& dets,
            const rgb_pixel color = rgb_pixel(0, 225, 225)
    )
    {

        std::vector<image_window::overlay_line> lines;

        for (unsigned long i = 0; i < dets.size(); ++i)
        {
            DLIB_CASSERT(dets[i].num_parts() == 68 || dets[i].num_parts() == 5,
                         "\t std::vector<image_window::overlay_line> render_face_lines()"
                                 << "\n\t You have to give either a 5 point or 68 point face landmarking output to this function. "
                                 << "\n\t dets["<<i<<"].num_parts():  " << dets[i].num_parts()
            );

            const full_object_detection& d = dets[i];

            if (d.num_parts() == 5)
            {
//                lines.push_back(image_window::overlay_line(d.part(0), d.part(1), color));
//                lines.push_back(image_window::overlay_line(d.part(1), d.part(4), color));
//                lines.push_back(image_window::overlay_line(d.part(4), d.part(3), color));
//                lines.push_back(image_window::overlay_line(d.part(3), d.part(2), color));
            }
            else
            {
                Delaunay<long> triangulation;
                std::vector< Vector2<long> > points;

                for(int i = 0; i < 68; i++) {
                    //convert part's to vector2's
                    points.push_back(Vector2<long>(d.part(i).x(), d.part(i).y()));
                    //load vector2's into delaunay generator


                    //generate delaunay

                    //get delaunay edges

                    //create lines for those edges

                    //push lines onto return object

                    //return
                }


                std::vector<Triangle<long>> triangles = triangulation.triangulate(points);
//                std::cout << triangles.size() << " triangles generated\n"; //todo Uncomment for num triangles
                std::vector<Edge<long>> edges = triangulation.getEdges();
//                std::cout << edges.size() << " edges generated\n";

                for(auto &e : edges) {
                    auto p1 = point(e.p1.x, e.p1.y);
                    auto p2 = point(e.p2.x, e.p2.y);
//                    point1.at(0) = e.p1.x;
//                    point1.at(1) = e.p1.y;
//
//                    const std::vector<long> point2(2);
//                    point1.at(0) = e.p2.x;
//                    point1.at(1) = e.p2.y;
                    lines.push_back(image_window::overlay_line(p1, p2, color));
                }

            }
        }
        return lines;
    }

// ----------------------------------------------------------------------------------------

    inline std::vector<image_window::overlay_line> render_face_lines (
            const full_object_detection& det,
            const rgb_pixel color = rgb_pixel(0,255,0)
    )
    {
        std::vector<full_object_detection> dets;
        dets.push_back(det);
        return render_face_lines(dets, color);
    }

// ----------------------------------------------------------------------------------------

}

#endif // DLIB_RENDER_FACE_DeTECTIONS_H_