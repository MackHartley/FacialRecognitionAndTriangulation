// Copyright (C) 2014  Davis E. King (davis@dlib.net)
// License: Boost Software License   See LICENSE.txt for the full license.
#ifndef DLIB_RENDER_FACE_POINTS_H_
#define DLIB_RENDER_FACE_POINTS_H_

#include "dlib/image_processing/full_object_detection.h"
#include "dlib/gui_widgets.h"
#include "dlib/image_processing/render_face_detections_abstract.h"
#include <vector>

namespace dlib
{
    inline std::vector<image_window::overlay_circle> render_face_points (
                                                                           const std::vector<full_object_detection>& dets,
                                                                           const rgb_pixel color = rgb_pixel(0,255,0)
                                                                           )
    {
        std::vector<image_window::overlay_circle> circles;
        for (unsigned long i = 0; i < dets.size(); ++i)
        {
            DLIB_CASSERT(dets[i].num_parts() == 68 || dets[i].num_parts() == 5,
                         "\t std::vector<image_window::overlay_line> render_face_points()"
                         << "\n\t You have to give either a 5 point or 68 point face landmarking output to this function. "
                         << "\n\t dets["<<i<<"].num_parts():  " << dets[i].num_parts()
                         );
            
            const full_object_detection& d = dets[i];
            
            int size = 2;
            
            if (d.num_parts() == 5)
            {
                circles.push_back(image_window::overlay_circle(d.part(0), size, color));
                circles.push_back(image_window::overlay_circle(d.part(1), size, color));
                circles.push_back(image_window::overlay_circle(d.part(2), size, color));
                circles.push_back(image_window::overlay_circle(d.part(3), size, color));
                circles.push_back(image_window::overlay_circle(d.part(4), size, color));
            }
            else
            {
                
                for(unsigned long i = 0; i <= 67; ++i) {
                    circles.push_back(image_window::overlay_circle(d.part(i), size, color));
                    circles.push_back(image_window::overlay_circle(d.part(i), size-1, color));
                }
            }
        }
        return circles;
    }
    
    // ----------------------------------------------------------------------------------------
    
    inline std::vector<image_window::overlay_circle> render_face_points (
                                                                           const full_object_detection& det,
                                                                           const rgb_pixel color = rgb_pixel(0,255,0)
                                                                           )
    {
        std::vector<full_object_detection> dets;
        dets.push_back(det);
        return render_face_points(dets, color);
    }
    
    // ----------------------------------------------------------------------------------------
    
}

#endif // DLIB_RENDER_FACE_DeTECTIONS_H_