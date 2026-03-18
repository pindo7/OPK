#pragma once

#include <string>
#include <opencv2/opencv.hpp>

namespace environment {

    struct Config {
        std::string map_filename;
        double resolution;y
    };

    class Environment {
    public:
        explicit Environment(const Config& config);

        bool isOccupied(double x, double y) const;

        double getWidth() const;

        double getHeight() const;

        double getResolution() const;

    private:
        cv::Mat image_;
        double resolution_;
    };

}