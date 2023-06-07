import qutip as qt

# Define the quantum state
psi = qt.basis(2, 0)  # Example: ground state of a 2-level system

# Define the observable
observable = qt.destroy(2) *qt.create(2)  # Example: lowering and raising operators

# Calculate the expectation value
expectation_value = qt.expect(observable,psi)

# Print the result
print("Expectation value using qutip:", expectation_value)
