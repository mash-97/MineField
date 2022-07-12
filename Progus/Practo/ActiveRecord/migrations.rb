require 'active_record'
require_relative 'connections'

include DBConnector
DBConnector.connectDatabase()
module Migrator	
	class UsersTable < ActiveRecord::Migration[5.2]
		def up()
			if not ActiveRecord::Base::connection.table_exists?(:users) then
				create_table :users do |table|
					table.string :name
					table.string :description
					table.integer :age
					table.timestamps()
				end
			end
		end
		
		def down()
			if ActiveRecord::Base::connection.table_exists?(:users) then
				drop_table :users
			end
		end
	end
	class ProfilesTable < ActiveRecord::Migration[5.2]
		def up()
			if not ActiveRecord::Base::connection.table_exists?(:profiles) then
				create_table :profiles do |table|
					table.integer :user_id
					table.timestamps()
				end
			end
		end
		
		def down()
			if ActiveRecord::Base::connection.table_exists?(:profiles) then
				drop_table :profiles
			end
		end
	end
	
	class PostsTable < ActiveRecord::Migration[5.2]
		def up()
			if not ActiveRecord::Base::connection.table_exists?(:posts) then
				create_table :posts do |table|
					table.integer :user_id
					table.timestamps()
				end
			end
		end
		
		def down()
			if ActiveRecord::Base::connection.table_exists?(:posts) then
				drop_table :posts
			end
		end
	end
	
	class ClansTable < ActiveRecord::Migration[5.2]
		def up()
			if not ActiveRecord::Base::connection.table_exists?(:clans) then
				create_table :clans do |table|
					table.timestamps()
				end
			end
		end
		
		def down()
			if ActiveRecord::Base::connection.table_exists?(:clans) then
				drop_table :clans
			end
		end
	end
	class ClansUsersTable < ActiveRecord::Migration[5.2]
		def up()
			if not ActiveRecord::Base::connection.table_exists?(:clans_users) then
				create_table :clans_users do |table|
					table.integer :user_id
					table.integer :clan_id
					table.timestamps()
				end
			end
		end
		
		def down()
			if ActiveRecord::Base::connection.table_exists?(:clans_users) then
				drop_table :clans_users
			end
		end
	end
end
