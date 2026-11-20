type Infotype_Billing <
    idBilling   : string
    namaUser    : string
    jamMulai    : string
    durasi      : integer
    totalBayar  : integer
>

type Adr_Billing : pointer to Elm_Billing
type Elm_Billing <
    info : Infotype_Billing
    next : Adr_Billing
>

type Infotype_Komputer <
    idPC        : string
    namaPC      : string
    tipe        : string
    tarifPerJam : integer
    status      : string
>

type Adr_Komputer : pointer to Elm_Komputer
type Elm_Komputer <
    info        : Infotype_Komputer
    nextBilling : Adr_Billing
    next        : Adr_Komputer
>

type List_Warnet <
    first : Adr_Komputer
>