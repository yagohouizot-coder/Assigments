#pragma once // prevent multiple inclusions of this file

#include <cstdlib>
#include <cassert>

namespace ecs {
using Entity = size_t;

/// @brief A sparse array based container that associates entities with components.
/// @tparam T The type of the component stored in this container.
template<typename T> class Container {
public:
	/// @brief Initializes an empty container.
	Container() {}

	/// @brief Checks if the given entity is included in the container.
	/// @param entity The entity to check.
	/// @return If `entity` is included in the container.
	bool has(const Entity entity) {}

	/// @brief Retrieve the component associated with the given entity.
	/// @param entity The entity whose component will be retrieved.
	/// @return A reference to the component associated to `entity`.
	T& get(const Entity entity) {}

	/// @brief Remove the component associated with the given entity.
	/// @param entity The entity whose component will be removed.
	void remove(const Entity entity) {}

	/// @brief Add an association between the given entity and component.
	/// @param entity The entity to add the association for.
	/// @param component The component to add.
	/// @return A reference to the newly added component.
	T& emplace(const Entity entity, const T& component) {}
private:
	// TODO: Add member variables such as the contained components here.
};

} // namespace ecs
