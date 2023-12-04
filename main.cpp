
#include <fdeep/fdeep.hpp>

int main() {
    const auto model = fdeep::load_model("output_json.json");
//    const auto result = model.predict(
//            {fdeep::tensor(fdeep::tensor_shape(static_cast<std::size_t>(3)),
//                           std::vector<float>{.21, .32, .83})});
//    std::cout << fdeep::show_tensors(result) << std::endl;
    return 0;
}
