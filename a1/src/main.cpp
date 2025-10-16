#include <cstdlib>
#include <ecs.hpp>

class Registry {
public:
	Registry() = default;
	ecs::Entity createEntity() {}

	// TODO: Add public members of the registry here.

private:
	// TODO: Add non-public members of the registry here.
};

int main(void) {
	Registry registry;

	// TODO: Create and modify entities as described in the task.
	//       Write some debugging info about the entities to the terminals after each chnage.

	// TODO: Are you using an "Array of Structs" or "Struct of Arrays"? Why is this the case?
	return EXIT_SUCCESS;
}
