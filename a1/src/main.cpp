#include <cstdlib>
#include <iostream>
#include <ecs.hpp>

struct Swim {};
struct Fly {};
struct Walk {};



class Registry {
public:
	Registry() = default;
	ecs::Entity createEntity() {
		return nextEntity++;
	}

	// TODO: Add public members of the registry here.

private:
	// TODO: Add non-public members of the registry here.
	ecs::Entity nextEntity = 0;
};

int main(void) {
	Registry registry;

	// TODO: Create and modify entities as described in the task.
	//       Write some debugging info about the entities to the terminals after each change.

	ecs::Container<Swim> swim;
	ecs::Container<Fly> fly;
	ecs::Container<Walk> walk;

	ecs::Entity salmon = registry.createEntity();
	ecs::Entity chicken = registry.createEntity();

	swim.emplace(salmon,Swim{});

	swim.emplace(chicken,Swim{});
	fly.emplace(chicken,Fly{});
	walk.emplace(chicken,Walk{});

	std::cout << "Salmon able to swim and chicken to swim,fly and walk\n";

	fly.emplace(salmon, Fly{});
	fly.remove(chicken);

	std::cout << "Salmon is now able to fly, not the chicken \n";

	std::cout << "Salmon can swim: " << swim.has(salmon) << "\n";
	std::cout << "Salmon can fly : " << fly.has(salmon)  << "\n";
	std::cout << "Chicken can fly: " << fly.has(chicken) << "\n";


	// TODO: Are you using an "Array of Structs" or "Struct of Arrays"? Why is this the case?

	std::cout << " The component storage model used is Struct of arrays\n";
	std::cout << "Every type of component is stored in its own array\n";
	return EXIT_SUCCESS;
}
