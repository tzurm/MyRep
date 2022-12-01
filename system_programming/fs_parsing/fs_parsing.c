#include "fs_parsing.h"

#define EXT2_NDIR_BLOCKS 12
#define EXT2_IND_BLOCK EXT2_NDIR_BLOCKS
#define EXT2_N_BLOCKS (EXT2_TIND_BLOCK + 1)
#define EXT2_DIND_BLOCK (EXT2_IND_BLOCK + 1)
#define EXT2_TIND_BLOCK (EXT2_DIND_BLOCK + 1)

#define BASE_OFFSET 1024 /* locates beginning of the super block (first group) */
#define EXT2_NAME_LEN 255
#define FD_DEVICE "/dev/ram0" /* the floppy disk device */
#define EXT2_SUPER_MAGIC 0xEF53
#define BASE_OFFSET_GROUP_DESC 4096
#define BASE_OFFSET_SUPER_BLOCK 1024

static unsigned int block_size = 0; /* block size (to be calculated) */
struct ext2_super_block
{
	__u32 s_inodes_count;	   /* Inodes count */
	__u32 s_blocks_count;	   /* Blocks count */
	__u32 s_r_blocks_count;	   /* Reserved blocks count */
	__u32 s_free_blocks_count; /* Free blocks count */
	__u32 s_free_inodes_count; /* Free inodes count */
	__u32 s_first_data_block;  /* First Data Block */
	__u32 s_log_block_size;	   /* Block size */
	__s32 s_log_frag_size;	   /* Fragment size */
	__u32 s_blocks_per_group;  /* # Blocks per group */
	__u32 s_frags_per_group;   /* # Fragments per group */
	__u32 s_inodes_per_group;  /* # Inodes per group */
	__u32 s_mtime;			   /* Mount time */
	__u32 s_wtime;			   /* Write time */
	__u16 s_mnt_count;		   /* Mount count */
	__s16 s_max_mnt_count;	   /* Maximal mount count */
	__u16 s_magic;			   /* Magic signature */
	__u16 s_state;			   /* File system state */
	__u16 s_errors;			   /* Behaviour when detecting errors */
	__u16 s_minor_rev_level;   /* minor revision level */
	__u32 s_lastcheck;		   /* time of last check */
	__u32 s_checkinterval;	   /* max. time between checks */
	__u32 s_creator_os;		   /* OS */
	__u32 s_rev_level;		   /* Revision level */
	__u16 s_def_resuid;		   /* Default uid for reserved blocks */
	__u16 s_def_resgid;		   /* Default gid for reserved blocks */
	/*
	 * These fields are for EXT2_DYNAMIC_REV superblocks only.
	 *
	 * Note: the difference between the compatible feature set and
	 * the incompatible feature set is that if there is a bit set
	 * in the incompatible feature set that the kernel doesn't
	 * know about, it should refuse to mount the filesystem.
	 *
	 * e2fsck's requirements are more strict; if it doesn't know
	 * about a feature in either the compatible or incompatible
	 * feature set, it must abort and not try to meddle with
	 * things it doesn't understand...
	 */
	__u32 s_first_ino;				/* First non-reserved inode */
	__u16 s_inode_size;				/* size of inode structure */
	__u16 s_block_group_nr;			/* block group # of this superblock */
	__u32 s_feature_compat;			/* compatible feature set */
	__u32 s_feature_incompat;		/* incompatible feature set */
	__u32 s_feature_ro_compat;		/* readonly-compatible feature set */
	__u8 s_uuid[16];				/* 128-bit uuid for volume */
	char s_volume_name[16];			/* volume name */
	char s_last_mounted[64];		/* directory where last mounted */
	__u32 s_algorithm_usage_bitmap; /* For compression */
	/*
	 * Performance hints.  Directory preallocation should only
	 * happen if the EXT2_COMPAT_PREALLOC flag is on.
	 */
	__u8 s_prealloc_blocks;		/* Nr of blocks to try to preallocate*/
	__u8 s_prealloc_dir_blocks; /* Nr to preallocate for dirs */
	__u16 s_padding1;
	__u32 s_reserved[204];
};
struct ext2_group_desc
{
	__u32 bg_block_bitmap;		/* Blocks bitmap block */
	__u32 bg_inode_bitmap;		/* Inodes bitmap block */
	__u32 bg_inode_table;		/* Inodes table block */
	__u16 bg_free_blocks_count; /* Free blocks count */
	__u16 bg_free_inodes_count; /* Free inodes count */
	__u16 bg_used_dirs_count;	/* Directories count */
	__u16 bg_pad;
	__u32 bg_reserved[3];
};

struct ext2_inode
{
	__u16 i_mode;		 /* File mode */
	__u16 i_uid;		 /* Low 16 bits of Owner Uid */
	__u32 i_size;		 /* Size in bytes */
	__u32 i_atime;		 /* Access time */
	__u32 i_ctime;		 /* Creation time */
	__u32 i_mtime;		 /* Modification time */
	__u32 i_dtime;		 /* Deletion Time */
	__u16 i_gid;		 /* Low 16 bits of Group Id */
	__u16 i_links_count; /* Links count */
	__u32 i_blocks;		 /* Blocks count */
	__u32 i_flags;		 /* File flags */
	union
	{
		struct
		{
			__u32 l_i_reserved1;
		} linux1;
		struct
		{
			__u32 h_i_translator;
		} hurd1;
		struct
		{
			__u32 m_i_reserved1;
		} masix1;
	} osd1;						  /* OS dependent 1 */
	__u32 i_block[EXT2_N_BLOCKS]; /* Pointers to blocks */
	__u32 i_generation;			  /* File version (for NFS) */
	__u32 i_file_acl;			  /* File ACL */
	__u32 i_dir_acl;			  /* Directory ACL */
	__u32 i_faddr;				  /* Fragment address */
	union
	{
		struct
		{
			__u8 l_i_frag;	/* Fragment number */
			__u8 l_i_fsize; /* Fragment size */
			__u16 i_pad1;
			__u16 l_i_uid_high; /* these 2 fields    */
			__u16 l_i_gid_high; /* were reserved2[0] */
			__u32 l_i_reserved2;
		} linux2;
		struct
		{
			__u8 h_i_frag;	/* Fragment number */
			__u8 h_i_fsize; /* Fragment size */
			__u16 h_i_mode_high;
			__u16 h_i_uid_high;
			__u16 h_i_gid_high;
			__u32 h_i_author;
		} hurd2;
		struct
		{
			__u8 m_i_frag;	/* Fragment number */
			__u8 m_i_fsize; /* Fragment size */
			__u16 m_pad1;
			__u32 m_i_reserved2[2];
		} masix2;
	} osd2; /* OS dependent 2 */
};

struct ext2_dir_entry_2
{
	__u32 inode;   /* Inode number */
	__u16 rec_len; /* Directory entry length */
	__u8 name_len; /* Name length */
	__u8 file_type;
	char name[EXT2_NAME_LEN]; /* File name */
};

/*----------------------------------------------------------------------------*/

/*
inode_t *ReadInode(const int fd, const int inode_num, inode_t *buffer)
{

}
int FindInDir(int fd, const char *file_name, inode_t *inode);
*/

/*
void PrintFileContent(inode_t *file_inode);
*/

group_desc_t *GetGroupDesc(const char *device_path)
{
	group_desc_t *group_desc = (group_desc_t *)malloc(sizeof(group_desc_t));
	/*check malloc */
	int fd = 0;

	/* open floppy device */
	if ((fd = open(FD_DEVICE, O_RDONLY)) < 0)
	{
		perror(FD_DEVICE);
		exit(1); /* error while opening the floppy device */
	}
	/* read super-block */
	lseek(fd, BASE_OFFSET_GROUP_DESC, SEEK_SET);
	read(fd, group_desc, sizeof(group_desc_t));
	close(fd);

	return group_desc;
}
super_block_t *GetSuperBlock(const char *device_path)
{
	super_block_t *super = (super_block_t *)malloc(sizeof(super_block_t));
	int fd;

	/* open floppy device */
	if ((fd = open(FD_DEVICE, O_RDONLY)) < 0)
	{
		perror(FD_DEVICE);
		exit(1); /* error while opening the floppy device */
	}

	/* read super-block */
	lseek(fd, BASE_OFFSET_SUPER_BLOCK, SEEK_SET);
	read(fd, super, sizeof(super_block_t));
	close(fd);
	if (super->s_magic != EXT2_SUPER_MAGIC)
	{
		fprintf(stderr, "Not a Ext2 filesystem\n");
		exit(1);
	}

	return super;
}

void PrintSuperBlock(super_block_t *super)
{
	block_size = 1024 << super->s_log_block_size;
	printf("------------------------------------------\n");
	printf("Reading super-block from device " FD_DEVICE ":\n"
		   "------------------------------------------\n"
		   "Inodes count            : %u\n"
		   "Blocks count            : %u\n"
		   "Reserved blocks count   : %u\n"
		   "Free blocks count       : %u\n"
		   "Free inodes count       : %u\n"
		   "First data block        : %u\n"
		   "Block size              : %u\n"
		   "Blocks per group        : %u\n"
		   "Inodes per group        : %u\n"
		   "Creator OS              : %u\n"
		   "First non-reserved inode: %u\n"
		   "Size of inode structure : %hu\n",
		   super->s_inodes_count,
		   super->s_blocks_count,
		   super->s_r_blocks_count,
		   super->s_free_blocks_count,
		   super->s_free_inodes_count,
		   super->s_first_data_block,
		   block_size,
		   super->s_blocks_per_group,
		   super->s_inodes_per_group,
		   super->s_creator_os,
		   super->s_first_ino,
		   super->s_inode_size);
}
/*
 */
void PrintGroupDesc(group_desc_t *group)
{
	printf("-----------------------------------------------------\n");
	printf("Reading first group-descriptor from device " FD_DEVICE ":\n"
		   "-----------------------------------------------------\n"
		   "Blocks bitmap block: %u\n"
		   "Inodes bitmap block: %u\n"
		   "Inodes table block : %u\n"
		   "Free blocks count  : %u\n"
		   "Free inodes count  : %u\n"
		   "Directories count  : %u\n",
		   group->bg_block_bitmap,
		   group->bg_inode_bitmap,
		   group->bg_inode_table,
		   group->bg_free_blocks_count,
		   group->bg_free_inodes_count,
		   group->bg_used_dirs_count);
}
