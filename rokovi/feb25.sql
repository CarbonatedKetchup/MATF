-- 1 zadatak
-- select sp.NAZIV smer, d.INDEKS, IME || ' ' || PREZIME ime, case
--                                                             when DATDIPLOMIRANJA is null
--                                                                 then 'Nije diplomirao'
--                                                             else 'Diplomirao pre ' || char(year(current_date ) - year(DATDIPLOMIRANJA)) || ' godina.'
--                                                             end poruka
-- from da.STUDIJSKIPROGRAM sp join da.DOSIJE d on d.IDPROGRAMA = sp.ID and year(d.DATUPISA) in (2015, 2017, 2019)
--     and d.MESTORODJENJA like '% %'
--     join da.NIVOKVALIFIKACIJE nk on nk.ID = sp.IDNIVOA
-- where d.IDSTATUSA=1

-- 2 zadatak
-- with tmp as(
--     select SKGODINA, IDPREDMETA, count(INDEKS) brojstudenata
--     from da.UPISANKURS
--     group by SKGODINA, IDPREDMETA
-- )
--
-- select sg.SKGODINA, p.NAZIV, tmp.brojstudenata br_studenata, 'Najvise studenata' komentar
-- from da.SKOLSKAGODINA sg join tmp on sg.SKGODINA = tmp.SKGODINA
-- join da.PREDMET p on p.ID = tmp.IDPREDMETA
-- where tmp.brojstudenata = (
--     select max(brojstudenata)
--     from tmp t2
--     where t2.SKGODINA = sg.SKGODINA
--     )
--
-- union
--
-- select sg.skgodina, p.naziv, tmp.brojstudenata, 'Najmanje studenata' komentar
-- from da.SKOLSKAGODINA sg join tmp on sg.SKGODINA = tmp.SKGODINA
-- join da.PREDMET p on p.ID = tmp.IDPREDMETA
-- where tmp.brojstudenata = (select min(brojstudenata)
--                            from tmp t2
--                            where t2.SKGODINA = sg.SKGODINA)
-- order by 3 desc, 1 asc



-- 3 zad
-- create table dodatni_poeni (
--     indeks integer not null primary key,
--     ukupni_poeni integer default 0,
--     espb_poeni integer,
--     dodatni_poeni integer default 0,
--     diplomirao_u_roku boolean
-- )

-- insert into dodatni_poeni (indeks, espb_poeni, diplomirao_u_roku)
-- select d.INDEKS, sum(p.ESPB), case
--                                                     when (year(DATDIPLOMIRANJA) - year(DATUPISA) <= 4) then true
--                                                     else false
--                                                 end
-- from da.DOSIJE d join da.ISPIT i on i.INDEKS = d.INDEKS and i.OCENA > 5 and STATUS='o'
-- join da.PREDMET p on p.ID = i.IDPREDMETA
-- where d.DATDIPLOMIRANJA is not null
-- group by d.INDEKS, DATUPISA, DATDIPLOMIRANJA

-- select *
-- from dodatni_poeni

-- update dodatni_poeni dp
-- set dp.dodatni_poeni = dp.dodatni_poeni + 5
-- where dp.diplomirao_u_roku = true
-- and not exists(select *
--                from da.ISPIT i
--                where i.INDEKS = dp.indeks and ocena <= 5 and status='o')

-- create trigger izmena
--     before update on dodatni_poeni
--     referencing
--         OLD as stari
--         NEW as novi
--     for each row
--     begin atomic
--         set novi.ukupni_poeni = novi.espb_poeni + novi.dodatni_poeni;
--     end;

-- create function izracunaj_popust(cena int, procenat int)
-- returns decimal
-- return case
--             when procenat > 100 then cena * 2.0
--             when procenat < 0 then cena / 100.0 * (100 + procenat)
--             else cena / 100.0 * (100 + procenat)
--         end

-- drop table dodatni_poeni
-- drop trigger izmena
-- drop function izracunaj_popust
