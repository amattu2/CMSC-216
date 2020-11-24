## Public Tests
- [X] public01.c
- [X] public02.c
- [X] public03.c
- [X] public04.c
- [X] public05.c
- [X] public06.c
- [X] public07.c
- [ ] public08.c
- [ ] public09.c
- [ ] public10.c

## Notes
IMPORTANT: The do_action command only executes commands with 2 arguments. Find a way to pass a char array of commands or something.

Potential edge cases:
- When the action line has multiple tabs after the first index between command spaces (Eg. echo abc 		def)
- Implement **split
- Test `is_older`, `exists`
- DO NOT USE strtok (Use split)
