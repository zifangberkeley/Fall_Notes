# Early DBMS
-   difficult to build and maintain. - tight coupling between logical and physical layers.
helpful to understand the physical layers.
- each record consists of a collection of related data values
- each value is formed by one or more bytes and corresponds to a particular field of the record.
Each column has a data type associated with it.

# File storage:
- most basical form, DBMS stores a database as files on disk.
- only the DBMS knows how to decipher their contents. they are encoded in a specific way to the DBMS
DBMS storage manager:
- responsible for managing a database files. 
-   represents files as a collection of pages
- keeps track of where everything is.

# Why it matters,
-   closer to the CPU -> faster storage but it's the smallest and most expensive.
-   further you get away from the CPU, the large it is but slower the storage is. 
-   DBMS also figures out how to move data between non-volatile disk and volatile memory since the system cannot operate on the data directly on the disk.

# Volatile vs non-volatile memory:
-   volatile memories: not stored
- non-volatile memories: stored locally.

# Database pages 
DBMS organizes the database across one or more file sin fixed size blocks of data called pages.
-   pages can contain different datas.
- most systems will not mix these types within pages
-   most systems are self contained (all the info needed to read each page is on the page itself)
Each page is given a unique identifier.
-   upper level of system will ask for a specific page number and storage manager will have to turn that page into a file.
Most DBMSs uses fixed size pages.
-   avoid the engineering overhead needed to support variable sized pages. 

# page access
The DBMS can locate a page on disk given a page id by using a linked list of pages
-   linked list: header page holds pointers to a list of free pages and a list of data pages.
    -   if DBMS is looking for a specific page, it has to do a sequential scan on the data page list until it finds the data it is looking for.

# Heap file
- place files in the order in which they are inserted.
    - this is called a heap file which sotres the unordered records, each insert is at the end of the file.
- Heap files are physical representation of data in our database
    - it consists of many pages,
    - it's the layer between DBMS and files on disk.

# What is a heap page
Tuples: where it keeps track of each row in a relational database table.
A page will contain one or more tuples. 
-   manages addition and deletion of tuples, ensures each tuple is written to a proper location and can be accessed as necessary
Consists of:
-   Header with metadata about the page
-   actual tuple data
-   free space for new or updated tuples
-   page size, DBMS version...
multiple heap pages makes up a heap file
- heap files also contain a header file for it's content.

# Tuple layout
Tuple: a sequence of bytes the DBMS interprets into attribute types and values
Tuple Header: contains meta data about the tuple
-   visibility information for the DBMS concurrency control protocol
Tuple Data
-   Schema and tuples. schema columns, tuples = rows.
- each tuple has unique identifier, which is based on page id and offset. 

# heap files are managed by catalogs
set of system tables that storaes metadata about the database structures.
- the DBMS stores their catalog inside themselves in the format that they use for their tables
read-write modify cycle is the rate limiting step. We can recover if something happens. 

# insertion:
- if subitable heap page is found:
    - new tuple is inserted into available space on the page
    - heap page free space is update. address is updated 
- if not found:
    - new page is added. header is updated

# search:
search is expensive
-   linear search through the file block by block.

# delete
delete is also expensive
-   we have to find the relavent block, copy the block into buffer, delete the record from buffer and then rewrite the block back to disk

reogranization: reclaim unused space of deleted record.
-   When we delete records, the record needs to condense to compact data. or keep it empty to be inserted new records.
-   need book keeping to keep where those empty boxes were. 

strategies:
grave, lazy, queue
grave: mark it as delete basically obscure it from the search.
lazy: delete and condense
queue: do it in a batch and delete when queue is full.
