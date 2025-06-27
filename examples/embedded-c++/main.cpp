#include "duckdb.hpp"

using namespace duckdb;

int main() {
	DuckDB db(nullptr);

	Connection con(db);

    con.Query("create table t1(id integer, name varchar)");
    con.Query("create table t2(pid integer, pname varchar)");
    con.Query("create table t3(kid integer, kname varchar)");
    con.Query("create table t4(mid integer, mname varchar)");
    con.Query("insert into t1 values (1, 'a'), (2, 'b'), (3, 'c')");
    con.Query("insert into t2 values (1, 'aa'), (2, 'bb'), (3, 'cc')");
    con.Query("insert into t3 values (1, 'aaa'), (3, 'ccc'), (4, 'ddd')");
    con.Query("insert into t4 values (1, 'aaaa'), (3, 'cccc')");

    // auto result = con.Query("select id, name, pname, kname from t1 inner join t2 on t1.id = t2.pid "
    //                         "left join t3 on t2.pid = t3.kid "
    //                         "where exists (select * from t4 where t3.kid = t4.mid)");

    auto result = con.Query("select id from t1 where len(name) < 2 group by id");
    result->Print();
}