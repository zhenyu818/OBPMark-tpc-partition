ptxas -arch=sm_72 -m64  "processing.ptx"  -o "processing.cubin" 
fatbinary --create="processing.fatbin" -64 --cicc-cmdline="-ftz=0 -prec_div=1 -prec_sqrt=1 -fmad=1 " -no-asm "--image3=kind=elf,sm=72,file=processing.cubin" --embedded-fatbin="processing.fatbin.c" 
gcc -E -x c++ -D__CUDACC__ -D__NVCC__  -O3 -I"./include/" -I"../common/" -I"/usr/local/cuda/include/" "-I/usr/local/cuda/bin/../targets/aarch64-linux/include"    -D "CUDA" -D__CUDACC_VER_MAJOR__=11 -D__CUDACC_VER_MINOR__=4 -D__CUDACC_VER_BUILD__=315 -D__CUDA_API_VER_MAJOR__=11 -D__CUDA_API_VER_MINOR__=4 -include "cuda_runtime.h" "src/ports/cuda/processing.cu" -o "processing.cpp4.ii" 
cudafe++ --c++14 --gnu_version=90400 --orig_src_file_name "src/ports/cuda/processing.cu" --allow_managed --unsigned_chars --unsigned_wchar_t  --m64 --parse_templates --gen_c_file_name "processing.cudafe1.cpp" --stub_file_name "processing.cudafe1.stub.c" --module_id_file_name "processing.module_id" "processing.cpp4.ii" 
gcc -D__CUDA_ARCH__=720 -c -x c++  -DCUDA_DOUBLE_MATH_FUNCTIONS -O3 -I"./include/" -I"../common/" -I"/usr/local/cuda/include/" "-I/usr/local/cuda/bin/../targets/aarch64-linux/include"   "processing.cudafe1.cpp" -o "../../build/3.1-aes_encryption/cuda/cuda_processing.o"