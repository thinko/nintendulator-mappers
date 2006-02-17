#include	"..\..\DLL\d_UNIF.h"
#include	"..\..\Hardware\h_MMC5.h"

static	void	_MAPINT	Shutdown (void)
{
	UNIF_SaveSRAM();
	MMC5_Destroy();
}

static	void	_MAPINT	Reset_EKROM (int IsHardReset)
{
	UNIF_InitSRAM(8192);
	MMC5.WRAMsize = MMC5WRAM_8KB_0KB;
	MMC5_Init();
}

static	void	_MAPINT	Reset_ELROM (int IsHardReset)
{
	MMC5.WRAMsize = MMC5WRAM_0KB_0KB;
	MMC5_Init();
}

static	void	_MAPINT	Reset_ETROM (int IsHardReset)
{
	UNIF_InitSRAM(8192);
	MMC5.WRAMsize = MMC5WRAM_8KB_8KB;
	MMC5_Init();
}

static	void	_MAPINT	Reset_EWROM (int IsHardReset)
{
	UNIF_InitSRAM(32768);
	MMC5.WRAMsize = MMC5WRAM_32KB_0KB;
	MMC5_Init();
}

CTMapperInfo	MapperInfo_NES_EKROM =
{
	"NES-EKROM",
	"MMC5 with 8KB SRAM",
	COMPAT_NEARLY,
	Reset_EKROM,
	Shutdown,
	NULL,
	MMC5_PPUCycle,
	MMC5_SaveLoad,
	MMC5_MapperSnd,
	NULL
};
CTMapperInfo	MapperInfo_NES_ELROM =
{
	"NES-ELROM",
	"MMC5 with no WRAM",
	COMPAT_NEARLY,
	Reset_ELROM,
	Shutdown,
	NULL,
	MMC5_PPUCycle,
	MMC5_SaveLoad,
	MMC5_MapperSnd,
	NULL
};
CTMapperInfo	MapperInfo_NES_ETROM =
{
	"NES-ETROM",
	"MMC5 with 16KB SRAM",
	COMPAT_NEARLY,
	Reset_ETROM,
	Shutdown,
	NULL,
	MMC5_PPUCycle,
	MMC5_SaveLoad,
	MMC5_MapperSnd,
	NULL
};
CTMapperInfo	MapperInfo_NES_EWROM =
{
	"NES-EWROM",
	"MMC5 with 32KB SRAM",
	COMPAT_NEARLY,
	Reset_EWROM,
	Shutdown,
	NULL,
	MMC5_PPUCycle,
	MMC5_SaveLoad,
	MMC5_MapperSnd,
	NULL
};