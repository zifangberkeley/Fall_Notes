# Define entities and attributes
first step: define your enetities and attributes
attribute can be singel valued or multivalued:
-   single valued attributes has a single value for a particular entity
-   multivalued attributes can have different number of values
We have to keep this in mind when designing.
Key attributes:
- values that must be unique for each individual entity in the entitty set.
    - used to identify each entity uniquely
    - constraints on any entity set of the entity type at any point in time.

# Database design
-   we will use diagrams to represent our design.
    - it's another type of UML diagram. symbols have some meanings. have to work through the exact example.

How do we establish relationships?
-   We can specify the degree of participating entity types in a relationship. 
-   Cardinality, the relationship is how many to how many
    - participation is not required for both, can be one sided.

# Normalization
-   reduce data redundancy, data is stored exactly in one place. 
-   accomplished by applying forms.
    -    we can denormalize tuple data by pre-joining them so the tables end up on the same page. makes updates more expensive. 

we can use sql:
-   a declarative language that specifies what we want, we don't have to worry about how we get it.

