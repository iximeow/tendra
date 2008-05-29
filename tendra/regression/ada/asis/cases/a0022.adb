------------------------------------------------------------------------------
--             G E L A   A S I S   R E G R E S S I O N   T E S T            --
--       ASIS implementation for Gela project, a portable Ada compiler      --
--                     http://www.ten15.org/wiki/Ada                        --
------------------------------------------------------------------------------
--  $TenDRA$
--  Purpose: Check bag-fix: use clause on renamed packages
--

with A0022A;
procedure A0022 (Text : String) is
use A0022A;
begin
   Put_Line (Text);
end;
