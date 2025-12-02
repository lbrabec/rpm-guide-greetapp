# greetapp

CLI greeting application using greetlib.

## Build (bundled)

```bash
git submodule update --init
cmake -B build
cmake --build build
```

## Build (system library)

```bash
cmake -B build -DUSE_BUNDLED_GREETLIB=OFF
cmake --build build
```

## Usage

```bash
./build/greetapp Alice
# Hello, Alice!
```

## License

MIT

