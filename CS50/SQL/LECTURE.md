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

## 10. Example workflow

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

These notes cover the SQL queries you tested and explain how they work in a relational database. Use this as a reference for `SELECT`, `WHERE`, `GROUP BY`, `ORDER BY`, `INSERT`, `DELETE`, and `UPDATE` operations.