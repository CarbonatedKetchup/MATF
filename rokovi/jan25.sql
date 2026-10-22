--1 zadatak
-- select d.INDEKS, d.IME, d.PREZIME, ss.NAZIV, case
--                                                 when OCENA is null then 'Nije polagao ispit u petak'
--                                                 else char(ocena)
--                                             end "Ocena/poruka"
--
-- from da.DOSIJE d join da.STUDIJSKIPROGRAM sp on d.IDPROGRAMA = sp.ID
-- join da.STUDENTSKISTATUS ss on d.IDSTATUSA = ss.ID
-- left join da.ISPIT i on i.INDEKS = d.INDEKS and dayname(i.DATPOLAGANJA) = 'Friday' and status='o'
--
-- where sp.NAZIV = 'Matematika' and ss.NAZIV='Budzet' and (ime like '% %' or prezime like '% %')



-- 2 zadatak
-- with
--     godine_studija(indeks, godina) as (
--         select indeks, count(ug.INDEKS)
--         from da.UPISGODINE ug
--         group by ug.INDEKS
--     ),
--     polozeno_espb(indeks, espb) as (
--         select i.INDEKS, sum(espb)
--         from da.ISPIT i join da.PREDMET p on p.ID = i.IDPREDMETA
--         where ocena > 5 and status='o'
--         group by i.INDEKS
--     )
-- select d.INDEKS, d.IME, d.PREZIME, (substr(d.MESTORODJENJA, 1, 1) || upper(substr(d.MESTORODJENJA, length(d.MESTORODJENJA), 1))) mesto_rodjenja, sp.NAZIV, p.espb broj_polozenih
-- from da.DOSIJE d join godine_studija g on g.indeks = d.INDEKS
-- join polozeno_espb p on p.indeks = d.INDEKS
-- join da.STUDIJSKIPROGRAM sp on sp.ID = d.IDPROGRAMA
-- where g.godina = 3 and p.espb > 90
--         and not exists(select *
--                        from da.DOSIJE d1 join godine_studija g1 on d1.INDEKS = g1.indeks
--                        where g1.godina = 3 and d1.MESTORODJENJA = d.MESTORODJENJA
--                        and d1.INDEKS <> d.INDEKS)



-- 3 zadatak
-- create table studentska_organizacija(
--     ID integer not null primary key,
--     ime varchar(50),
--     prezime varchar(50),
--     tim varchar(2) not null check (tim in ('CR', 'PR', 'HR', 'IT')),
--     datum_uclanjenja_u_org date not null,
--     datum_uclanjenja_u_tim date,
--     upravni_odbor boolean default false,
--     foreign key indeks_fk (id) references da.DOSIJE
-- )
--
-- create function clan_organizacije(ind int)
-- returns varchar(200)
-- return case
--         when ind in (select ID from studentska_organizacija)
--             then 'Student jeste clan organizacije.'
--         else
--             'Student nije clan organizacije.'
--     end
--
-- insert into studentska_organizacija (ID, ime, prezime, tim, datum_uclanjenja_u_org, datum_uclanjenja_u_tim)
-- select d.INDEKS, ime, prezime, case
--                         when sp.NAZIV = 'Informatika' then 'IT'
--                         when sp.NAZIV = 'Astronomija i astrofizika' then 'CR'
--                         when sp.NAZIV = 'Matematika' and IDNIVOA=1 then 'HR'
--                         else 'PR'
--                     end, d.DATUPISA, date('15.3.2025')
-- from da.DOSIJE d join da.STUDIJSKIPROGRAM sp on d.IDPROGRAMA = sp.ID
-- where MESTORODJENJA = 'Novi Sad'

-- update studentska_organizacija so
-- set so.upravni_odbor = true
-- where not exists (select *
--                   from studentska_organizacija so1
--                   where so.tim = so1.tim
--                   and so1.datum_uclanjenja_u_org > so.datum_uclanjenja_u_org)

-- create trigger prekvalifikacija
--     before update on studentska_organizacija
--     referencing
--         OLD as stari
--         NEW as novi
--     for each row
--     begin atomic
--         set novi.tim = case when
--                             months_between(stari.datum_uclanjenja_u_tim, current_date) < 6
--                         then
--                             stari.tim
--             end;
--         set novi.datum_uclanjenja_u_tim = case when stari.tim <> novi.tim then current_date end;
--     end;

delete from studentska_organizacija
where ID not in (select indeks from da.DOSIJE where DATDIPLOMIRANJA is null)






