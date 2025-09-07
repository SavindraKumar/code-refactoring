🔎 Why is this a Long Method Smell?

Validation, diagnosis, medication assignment, billing, persistence, and reporting are all mixed together.

Hard to test each concern separately.

Difficult to extend (e.g., adding new billing rules requires digging through everything).

Violates Single Responsibility Principle (SRP).