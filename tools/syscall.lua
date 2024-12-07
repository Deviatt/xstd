local sysfmt = "SYS(%s)"
local unufmt = "SYS(UNUSED%d)"

local fp = (...)

local file = io.open(fp, "rb")
if (file) then
	local syscalls = {}
	local unused, i = 0, 0
	for line in file:lines() do
		-- ignore '#'
		if (line:byte() ~= 35) then
			local id, name = line:match("(%d+)%s+.-%s+(.-)%s+")
			if (id) then
				id = tonumber(id)
				if ((id - i) > 1) then
					for j = i + 1, id - 1 do
						syscalls[j], unused = unufmt:format(unused), unused + 1
					end
				end

				syscalls[id] = sysfmt:format(name:upper())
				i = id
			end
		end
	end

	file:close()
	file = io.open("syscalls.h", "w")
	file:write(("enum {\n\t%s\n};"):format(table.concat(syscalls, '\n\t', 0)))
	file:close()

	print(("Found %d syscalls in table (%s)"):format(#syscalls, fp))
else
	error("File not found!")
end