# SQL Notes for Relational Databases

## 1. Relational database basics

- A relational database stores data in tables.
- Each table has rows and columns.
- A table usually has a primary key and one or more columns representing fields.
- Tables can be queried using SQL (Structured Query Language).
- Example table: `favorites`
  - columns: `language`, `Problem`, `Timestamp` (optional)

## 2. SELECT queries

### 2.1 Select all columns

```sql
SELECT * FROM favorites;
```
- `*` returns every column for every row.

### 2.2 Select specific columns

```sql
SELECT language FROM favorites;
```
- Returns only the `language` column values.

## 3. Aggregate functions

### 3.1 Count rows

```sql
SELECT COUNT(*) FROM favorites;
```
- `COUNT(*)` counts all rows in the table.

### 3.2 Count distinct values

```sql
SELECT DISTINCT language FROM favorites;
```
- `DISTINCT` returns unique values from the selected column.

```sql
SELECT COUNT(DISTINCT language) FROM favorites;
```
- Counts how many unique languages appear.

## 4. Filtering rows with WHERE

### 4.1 Simple filter

```sql
SELECT COUNT(*) FROM favorites WHERE language = 'c';
```
- Counts rows where `language` is exactly `'c'`.

### 4.2 Combined conditions with AND

```sql
SELECT COUNT(*) FROM favorites
WHERE language = 'python' AND Problem = 'Hello World';
```
- Both conditions must be true.

### 4.3 Using OR and parentheses

```sql
SELECT COUNT(*) FROM favorites
WHERE language = 'python' AND (Problem = 'Hello World' OR Problem = 'Recover');
```
- The parentheses group the OR conditions.
- Meaning: count rows where `language` is `'python'` and `Problem` is either `'Hello World'` or `'Recover'`.

### 4.4 Pattern matching with LIKE

```sql
SELECT COUNT(*) FROM favorites
WHERE language = 'python' AND Problem LIKE 'Hello, %';
```
- `LIKE` matches text patterns.
- `%` means zero or more characters.
- This counts python rows where the `Problem` begins with `Hello, `.

## 5. GROUP BY for aggregation

### 5.1 Group by a column

```sql
SELECT language, COUNT(*) FROM favorites GROUP BY language;
```
- Groups rows by `language` and counts rows in each group.
- The result shows one row per language.

### 5.2 Order groups by count ascending

```sql
SELECT language, COUNT(*) FROM favorites
GROUP BY language
ORDER BY COUNT(*);
```
- Sorts group results from smallest to largest count.

### 5.3 Order groups by count descending

```sql
SELECT language, COUNT(*) FROM favorites
GROUP BY language
ORDER BY COUNT(*) DESC;
```
- Sorts from largest to smallest count.

### 5.4 Use aliases for readability

```sql
SELECT language, COUNT(*) AS n FROM favorites
GROUP BY language
ORDER BY n DESC;
```
- `AS n` gives the count column a name.
- `ORDER BY n DESC` sorts by the alias.

### 5.5 Limit the result

```sql
SELECT language, COUNT(*) AS n FROM favorites
GROUP BY language
ORDER BY n DESC
LIMIT 1;
```
- Returns only the top row after sorting.
- Useful for finding the most common language.

## 6. Inserting data

### 6.1 Add a new row

```sql
INSERT INTO favorites (language, Problem)
VALUES ('c', 'hello, world');
```
- Adds one row with values for `language` and `Problem`.
- If the table has more columns, either provide values for them or rely on defaults.

### 6.2 Verify insert

```sql
SELECT * FROM favorites;
```
- Confirms the new row was added.

## 7. Deleting data

### 7.1 Delete rows with conditions

```sql
DELETE FROM favorites WHERE Timestamp IS NULL;
```
- Removes rows where `Timestamp` has no value.
- Always include a condition unless you want to remove every row.

### 7.2 Delete all rows

```sql
DELETE FROM favorites;
```
- Deletes every row in the table.
- This is destructive; use carefully.
- Some SQL engines require a terminating semicolon.

> Note: `DELETE FROM table WHERE conditions;` must end with a semicolon in SQL shells. Without a `WHERE` clause, all rows are removed.

## 8. Updating data

### 8.1 Change row values

```sql
UPDATE favorites
SET language = 'c', Problem = 'Hello, World';
```
- Updates every row in the table because no `WHERE` clause is included.
- All existing rows will become `language = 'c'` and `Problem = 'Hello, World'`.

### 8.2 Use WHERE to update selectively

```sql
UPDATE favorites
SET language = 'c', Problem = 'Hello, World'
WHERE language = 'python';
```
- Only rows matching the `WHERE` condition are updated.

## 9. General SQL tips

- Always end SQL statements with a semicolon (`;`) when using command-line tools.
- Use `SELECT *` only for quick checks; prefer selecting specific columns in production.
- Use `WHERE` to avoid unintended updates or deletes.
- Use `GROUP BY` with aggregate functions like `COUNT()`, `SUM()`, `AVG()`, `MIN()`, `MAX()`.
- `DISTINCT` removes duplicate values from query results.
- `LIKE` is case-sensitive in many SQL engines; use functions like `LOWER()` if needed.
- Use `ORDER BY` to sort results and `LIMIT` to restrict how many rows are returned.

## 10. IMDb-style tables, relationships, and joins

### 10.1 Table relationships

- `shows` and `ratings` are two related tables.
- `shows` might contain one row per show.
- `ratings` might contain many rows for the same show, one row per rating.
- This is a one-to-many relationship: one show can have many ratings.
- A one-to-one relationship means each row in one table matches exactly one row in another table.
  - Example: `show_details` may store one detail row for each show in `shows`.

### 10.2 Example queries

```sql
SELECT * FROM shows LIMIT 10;
```
- Shows the first 10 rows from the `shows` table.

```sql
SELECT show_id FROM ratings
WHERE rating >= 6.0
LIMIT 10;
```
- Finds up to 10 rating rows for shows with rating 6.0 or higher.

```sql
SELECT * FROM shows
WHERE id IN (
    SELECT show_id FROM ratings
    WHERE rating >= 6.0
    LIMIT 10
);
```
- Uses a subquery to find shows whose `id` appears in the qualifying rating rows.
- The subquery returns show IDs meeting the rating condition.

```sql
SELECT * FROM shows
JOIN ratings ON shows.id = ratings.show_id
WHERE ratings.rating >= 6.0
LIMIT 10;
```
- Joins `shows` with `ratings` using the matching show ID.
- Returns combined rows from both tables where the rating is at least 6.0.
- This is the usual way to combine rows from related tables.

> Note: In SQL, the table name must be correct. If the table is `ratings`, use `ratings` consistently. The join condition should use the correct column names, such as `shows.id = ratings.show_id`.

## 11. One-to-many relationships

One-to-many relationships link a single row in one table to multiple rows in another.

### 11.1 Basic one-to-many queries

```sql
SELECT genre FROM genres WHERE show_id = 5847;
```
- Returns all genres associated with show ID 5847.
- One show has many genres.

```sql
SELECT id FROM shows WHERE title = 'Catweazle';
```
- Finds the show ID by title.

### 11.2 Nested subqueries

```sql
SELECT id FROM shows WHERE id = (
    SELECT id FROM shows WHERE title = 'Catweazle'
);
```
- A subquery returns the matching show ID, then the outer query filters by that ID.

```sql
SELECT * FROM shows
JOIN genres ON shows.id = genres.show_id
WHERE shows.id = 58947;
```
- Joins `shows` and `genres` on the show ID.
- Returns the show and all its genres in one result set.

```sql
SELECT genre FROM shows
JOIN genres ON shows.id = genres.show_id
WHERE shows.id = 784545;
```
- Returns only genre names for a specific show.

### 11.3 Finding shows by title

```sql
SELECT * FROM shows WHERE title = 'The Office';
```
- Returns all rows for shows with that title.

```sql
SELECT * FROM shows
WHERE title = 'The Office' AND year = 2005;
```
- Narrows results by adding a year condition.

### 11.4 Finding people in a show

```sql
SELECT person_id FROM stars
WHERE show_id = (
    SELECT id FROM shows
    WHERE title = 'The Office' AND year = 2005
);
```
- Finds all actors (person IDs) in a specific show.
- The inner subquery gets the show ID, the outer gets matching person IDs.

```sql
SELECT name FROM people
WHERE id IN (
    SELECT person_id FROM stars
    WHERE show_id = (
        SELECT id FROM shows
        WHERE title = 'The Office' AND year = 2005
    )
);
```
- Returns the actual names of all actors in the show.
- Multiple nested subqueries: find show → find person IDs → find names.

### 11.5 Finding shows by actor name

```sql
SELECT title FROM shows
WHERE id IN (
    SELECT show_id FROM stars
    WHERE person_id = (
        SELECT id FROM people
        WHERE name = 'Steve Carell'
    )
);
```
- Finds all shows featuring a specific actor.
- The innermost subquery returns the actor's person ID.

### 11.6 Multiple joins in one query

```sql
SELECT title FROM shows
JOIN stars ON shows.id = stars.show_id
JOIN people ON stars.person_id = people.id
WHERE people.name = 'Steve Carell';
```
- Uses multiple JOINs to connect three tables at once.
- Returns show titles for the given actor.

### 11.7 Implicit joins using comma syntax

```sql
SELECT title FROM shows, stars, people
WHERE shows.id = stars.show_id
AND people.id = stars.person_id
AND people.name = 'Steve Carell';
```
- An alternative join syntax using commas instead of explicit JOIN keywords.
- The WHERE clause performs the join conditions.
- Functionally equivalent to explicit JOINs but less readable.

### 11.8 View table schema

```sql
.schema writers
```
- A SQLite command that displays the structure of the `writers` table.
- Shows column names, types, and constraints.

## 12. Indexes for query optimization

Indexes speed up queries by creating a lookup structure for columns.

### 12.1 Enable timing

```sql
.timer ON
```
- A SQLite command that displays query execution time.
- Helps measure the performance impact of indexes.

### 12.2 Query without index

```sql
SELECT * FROM shows WHERE title = 'The Office';
```
- Without an index on `title`, SQLite scans every row (full table scan).
- This is slow for large tables.

### 12.3 Create an index

```sql
CREATE INDEX title_index ON shows (title);
```
- Creates an index named `title_index` on the `title` column of `shows`.
- Indexes are sorted data structures that enable fast lookups.

### 12.4 Query with index

```sql
SELECT * FROM shows WHERE title = 'The Office';
```
- With the index, SQLite uses it to find matching rows quickly.
- Much faster than a full table scan for large datasets.

> Tip: Create indexes on columns used frequently in `WHERE` clauses or JOIN conditions. Too many indexes can slow down inserts and updates.

## 13. Example workflow

1. Inspect rows:
   ```sql
   SELECT * FROM favorites;
   ```
2. Count rows:
   ```sql
   SELECT COUNT(*) FROM favorites;
   ```
3. Find unique languages:
   ```sql
   SELECT DISTINCT language FROM favorites;
   ```
4. Add a favorite record:
   ```sql
   INSERT INTO favorites (language, Problem) VALUES ('c', 'hello, world');
   ```
5. Remove bad rows:
   ```sql
   DELETE FROM favorites WHERE Timestamp IS NULL;
   ```
6. Aggregate by language:
   ```sql
   SELECT language, COUNT(*) AS n FROM favorites
   GROUP BY language
   ORDER BY n DESC;
   ```

---

These notes cover the SQL queries you tested and explain how they work in a relational database. Use this as a reference for `SELECT`, `WHERE`, `GROUP BY`, `ORDER BY`, `INSERT`, `DELETE`, `UPDATE`, `JOIN`, subqueries, and indexes.

## 14. Python and SQL

- Python can interact with SQL databases directly (e.g., `sqlite3`, `psycopg2`, `mysql-connector`) or via ORMs (e.g., SQLAlchemy, Django ORM).
- Use parameterized queries to avoid SQL injection and to let the DB engine optimize queries.

Example using `sqlite3` (safe parameterized query):

```python
import sqlite3

conn = sqlite3.connect('shows.db')
cur = conn.cursor()

# Parameterized - use placeholders and a tuple
cur.execute("SELECT title FROM shows WHERE year = ?", (2005,))
for (title,) in cur.fetchall():
    print(title)

conn.close()
```

- With ORMs you write Python objects and let the ORM generate SQL; still prefer parameterized filters.
- Use transactions (`BEGIN` / `COMMIT`) when modifying multiple rows to keep changes atomic.

## 15. Race conditions (in databases)

- A race condition occurs when concurrent operations interleave and produce incorrect or unexpected results (e.g., lost updates).
- Example: two clients read a balance, both subtract 10, both write back — one update is lost.

Mitigations:
- Use transactions to group reads and writes: `BEGIN TRANSACTION; ... COMMIT;`.
- Use appropriate isolation levels (e.g., `READ COMMITTED`, `REPEATABLE READ`, `SERIALIZABLE`) when supported.
- Use row-level locks (`SELECT ... FOR UPDATE`) or optimistic locking (a `version` column that you check/update atomically).
- In SQLite, take care: default isolation and locking behavior differs from client-server DBs; use transactions explicitly.

## 16. SQL injection attacks

- SQL injection happens when untrusted input is concatenated into SQL, allowing attackers to change the query.
- Vulnerable example (do NOT use):

```python
user = "'; DROP TABLE users; --"
query = f"SELECT * FROM users WHERE name = '{user}'"
cur.execute(query)
```

Safe practices:
- Use parameterized queries / prepared statements (placeholders) instead of string interpolation.
- Example (safe):

```python
cur.execute("SELECT * FROM users WHERE name = ?", (user,))
```

- Use ORMs or query builders that automatically parameterize values.
- Validate and sanitize input where appropriate (e.g., ensure numeric values are numeric).
- Apply least privilege: database users should have only necessary permissions.
- Keep DB software and drivers up-to-date and monitor for suspicious queries.

---

These notes cover the SQL queries you tested and explain how they work in a relational database. Use this as a reference for `SELECT`, `WHERE`, `GROUP BY`, `ORDER BY`, `INSERT`, `DELETE`, `UPDATE`, `JOIN`, subqueries, indexes, transactions, and security best practices.