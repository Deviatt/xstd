target "xstd"
	set_kind "static"

	add_files "src/**.c"
	add_includedirs "inc"

	set_strip "all"
	set_optimize "fastest"

	add_cflags "gcc::-ffreestanding -nostdlib -nostdinc"
	add_cflags "clang::-ffreestanding -nostdlib -nostdinc"