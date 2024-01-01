mkdir -p build/
cd build/
cmake ../
cmake --build .

env > env_vars.log