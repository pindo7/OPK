#pragma once

#include <vector>
#include <memory>
#include "types/Geometry.h"
#include "environment/Environment.h"

namespace lidar {

    struct Config {
        double max_range;
        int    beam_count;
        double first_ray_angle; // relative to robot heading, radians
        double last_ray_angle;  // relative to robot heading, radians
    };

    class Lidar {
    public:
        Lidar(const Config& config, std::shared_ptr<environment::Environment> env);

        std::vector<geometry::Point2d> scan(const geometry::RobotState& state) const;

    private:
        Config config_;
        std::shared_ptr<environment::Environment> env_;

        bool castRay(double origin_x, double origin_y, double angle,
                     geometry::Point2d& hit_point) const;
    };

} // namespace lidar