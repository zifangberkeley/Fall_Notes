SQL
CRUD app. Allows users to interact with a database by performing four operations on data.
- create, insert
- select
- update, delete and drop

advance data retrieval:
group by:
order by:

How did we get to SQL?
relation algebra:
-   A set of tuples.
Given this tuple, all queries can be broken down using relaional algebra.
- they operate on sets, set of tuples.. etc
- Unary: select, project, rename
- Relational, Union, intersection,Difference, Cartesian Product. 

Relational algebra, manipulate tuples in a relation
- each operator takes in one or more relations as inputs and outputs a new relation
- to write queries, we "chain" these operators together to create more complex operations.

Unary: Select[where analog] takes in a relation and outputs a subset of the tuples from that relation that satisfy a selection predicate ( filter ).
- predicates acts like filters and can combine multiple predicates
- Horizontal operation. filtering roles of data. 
- Commutative -> sequence of selects can be applied in any order.
- Syntax o predicate(R)

Projection. [select analog] Takes in a relation and outputs a relation with tuples that contains only specific atributes. 
- vertical operation
- can also rearrange the ordering of attributes in the input relation.
- not commutative
- syntax piA1A2(R)

Rename [AS analog]
role of a DBMS. Duplicate tuples are removed
we can't have duplicates in a set. 

UNION RUS includes all tuples in R, in S or in both R and S 
- relations must contain the same number of columns
- columns must have the same data type
- commutative 
SQL Syntax: Select * From --- Union Select * From ---

Intersection and Difference 
includes all tuples that are in one but not the other 

Cartesian
- combine tuples from two relations combinatorically .
- it's useful in implementing a join operation.

Join: takes two sets of tuples and and combine them together
- way to combine information from multiple tables,
- there's inner join and outer join. 

Observations:
Relational algebra is procedural: defines high level steps of how to compute a query 

Better appraoch: say the result you want, and let the DBMS figure out the steps to take to compute the query.
-   SQL will do this, it's the standard for writing queries on relational model databses,
- SQL is a declarative language
    - declaration is turned into series of relational algebra expression that computer will carry out procedurally.
- Recall order of operations from async session
    - FROM happens first, then where, then select then order by. 
    - the order of the clause is taken cared by the DBMS

Query trees
- Data structure used to organize the operations to be performed
    - leaves of trees are starting relations


Query Processing model:
DBMS processing model: defines how the system executes a query plan 
-   Direction in which query plan is read, what kind of data is passed between operators along the way 
- many models with various trade-offs for different workloads
Iterator model: most common processing model used by almost every row based DBMS. 

Query optimization:
Optimization is difficult. query optimization is the most difficult part of building a DBMS
-   many possible combinations of query trees can satisfy the query.
- Goal isnt to find the most optimal or best query tree
    - just need to come up with something good enough
- need to decide which operations to focus on for optimization. there might be trade offs, make one better might make another worst. 
    - select(where in relational algebra)

Heuristics: manipulating the query tree directly can optimize queries .
- one tree can be rewritten in numerous ways, the fastest version is query rewriting 
    - Select:
    break up conjunctive select operations: allows us to move the arround more easily.
    we move the more restricting operation towards the bottom. 
    We can then combine cartesian products with selects when applicable. We can then move tthe things down the tree as far as possible. 

    They can be executed parallel execution. DBMS executes queries in parallel with multiple wworkers.
    -   increase perforamnce in throughout and latency 

    Beyond query optimization, we can do indexing where we index our table to find data we need and avoid useless operations. Index it into a dictionary structure and have a constant time look up. 

    Transaction, management and concurrency control.

    How are the queries optimized? the DBMS manages its memory and moving data bac and forth from the disk.
    data cannot be directy operated on in the disk, any database must be able to efficiently move data representated as files on its disk into memroy so that it can be used.
    - it will be modified in the memory before putting it into the file itself.
    - DBMS face the problem of minimizing slowdown of moving data, ideally it shoud appear as minimal effect.

    DBMS control:
    - Spatial control: where pages are phsically written on disk. keep pages that are used together often as phyiscally close together as possible on disk
    - temporal control: when to rea pages into memory and when to write them to disk. minimize the number of stalls from having to read data from disk.

    Where does the data go? Butter pool
    - Buffer pool: in memory cache of pages read from disk
        - essentially a large memory region allocated inside of the database to store pages that are fetched from disk.

    Transaction: basic unit of change in DBMS
    -   partial transactions are not allowed.
    - it's the logical grouping of operations, and executes a sequence of one or more operations on a shared database to perform higher level function

    There are two basic operations fro each item: read and write. 
    There are some core properties of transactions
    A - atomicity: treated as a single unit: everything happens or none of it happens
    C - consistency preservation: want to move from one consistent state to another consistent state. no in between
    I - isolation. Each transaction is isolated from each other and should all behave the same way.
    D - Durability: once those changes are made, they are permanent and the changes will not be lost (i.e those changes persist)

    How does it protect against cases where many people are interacting with the data base and update conflicts could coccur.
    -    multiple threads are allowed to read the same items at the same time.
    -   thread can acquire the read latch even if another thread has aquired it as well.
    Write:
    -   only one thread allowed to access the item.
    -   thread cannot acquire a write latch if another thread holds the latch in any mode.
    -   thread holding a write latch also prevents other threads from acquiring a read latch. 

    A few ways it can go wrong is the lost update problem
    -   T1 reads in x and modifies x but before it can write and modify version of x, T2 reads in the original version of X and modifies it.
    -   Then T1 writes it change to X which is then stored. T2 overwrites that change with it's own change,
    -   update to x from T1 is lost.

    Temporary update problem
    - t1 fails for some reason then x will revert back to its previous value. But transaction 2 already read the incorrect value of x. it no longer exists due to a rollback. 

    Incorrect summar problem
    - one transaction is aplpying the aggregate function while another update these records, it will give out the wrong sum without the updates.

    Unrepeatable read problem:
    - occurs when same value is read twice but modified in between.
    - we expect the result to be same for both but the read can be wrong.

    Transaction states: for managing transactions

    States:
    - begin Transaction
    - Read or Write
    - End Transaction
    ---

    it's not fully commited until a log file is produced. it's a sequential append only list of transaction states. kind of like version control but  for data bases.

    Recovery, once committed, there are recovery processes that can ocure. 

    Transaction schedules:
    - know the inline format and visual format of correct transaction schedules.

    How do we know if it will be problematic.
    -   conflicts, predicting when conflicts will happen.
    -   operations from different transactions trying to access the same item. we have a read write conflict. or a write/write conflict. We have to be aware of these

    Serial vs non-serial schedules 
    serial schedules will always work, conflicts may exist but will not lead to update issues.
    one by one transactions. a casacading series of transactions. hwoever, if one gets stuck, then everything is stuck waiting .

    We want to use non-serial schedules, 
    -  but without the uncertainties.

    Serializable schedules:
    -   any schedule that's equivalent to a serial schedule
    