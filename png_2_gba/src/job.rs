mod toml;
mod serde;

use serde_derive::Deserialize;

use std::fs;

#[derive(Deserialize)]
pub struct SourceGroup {
	name: String,
	sources: Vec<String>
}
#[derive(Deserialize)]
enum Format {
	TilePack4Bpp,
	TileAsset4Bpp,
	Palette16,
	SoundAsset,
	BinaryAsset,
	TextAsset,
}

#[derive(Deserialize)]
enum ResourceArg {
	Width(i64),
	Height(i64),
	Paletize,
}

#[derive(Deserialize)]
pub struct Resource {
	name: String,
	source_groups: Vec<String>,
	source_resources: Vec<String>,
	format: Format,
	args: Vec<ResourceArg>
}

#[derive(Deserialize)]
pub struct ResourceExport {
	name: String,
	prefix: Option<String>,
}

#[derive(Deserialize)]
pub struct Output {
	name_prefix: String,
	resources: Vec<ResourceOutput>,
}

#[derive(Deserialize)]
pub struct Job {
	source_groups: Vec<SourceGroup>,
	resource_exports: Vec<ResourceExport>,
	hpp_output_dir: String,
	cpp_output_dir: String,
	
}

fn open_job_file(file_name: String) -> Result<Job, String> {
	match fs::read_to_string(&Path::new(file_name)) {
		Ok(file_str) => {
			match toml::from_str(file_str) {
				Ok(job) => Ok(job),
				Err(error) => Err(format!("error parsing job file:{:?}", error))
			}
		},
		Err(_) => {
			Err(format!("failed to read file {}", file_name))
		}
	}
}

