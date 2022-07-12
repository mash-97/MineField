require 'active_record'

module DBConnector
	def connectDatabase()
		db_config = YAML::load(File.open("sqlite_manifesto.yaml"))
		ActiveRecord::Base.establish_connection(db_config)
	end
end

