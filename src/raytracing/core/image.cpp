#include <raytracing/core/image.h>

Image::Image(
    const std::string& filename_,
    const int& width_, const int& height_,
    const FileType& file_type_,
    bool bit_by_bit_
)
    : filename{ filename_ }
    , width{ width_ }, height(height_)
    , file_type{ file_type_ } 
    , bit_by_bit{ bit_by_bit_ }
{
    aspect_ratio = static_cast<double>(width) / static_cast<double>(height);

    if (!bit_by_bit) {
        pixels.reserve(width * height);
    }
}

void Image::AddSample(std::size_t x, std::size_t y, const Color& c) {
    // 检查坐标是否越界
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return;
    }

    // 将颜色信息加到对应像素上
    pixels[y * width + x] += c;
}

void Image::WriteColor(std::ostream& out, Color pixel_color) {
    auto r = pixel_color.x;
    auto g = pixel_color.y;
    auto b = pixel_color.z;

    out << static_cast<int>(256 * Clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * Clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * Clamp(b, 0.0, 0.999)) << '\n';
}

Image Image::basic_image() {
    const int image_width = 1920;
    const int image_height = 1080;
    const std::string name = "image";
    FileType file_type = FileType::PPM;
    bool bit_by_bit = true;
    Image image(name, image_width, image_height, file_type, bit_by_bit);

    return image;
}