#ifndef IMAGE_H_
#define IMAGE_H_

#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include <basic/vector/vector3.h>

enum class FileType { PPM, PNG, JPG };

class Image {
public:
    FileType file_type = FileType::PPM;
    std::string filename { "image"};
    const int width { 1920 };
    const int height { 1080 };
    double aspect_ratio { 16.0 / 9.0};
    bool bit_by_bit = true;
    std::vector<Color> pixels;

public:
    Image(
        const std::string& filename_ = "image",
        const int& width_ = { 1920 }, const int& height_ = { 1080 },
        const FileType& file_type = FileType::PPM,
        bool bit_by_bit_ = true
    );

    void AddSample(std::size_t x, std::size_t y, const Color& c);
    void WriteColor(std::ostream& out, Color pixel_color);
    void WriteImageToFile(const std::string& filename, FileType type = FileType::PPM);

    static Image basic_image();
};
#endif // IMAGE_H_