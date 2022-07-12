#! /usr/bin/env ruby
require 'active_record'	
require 'yaml'


module TablesModels
	

# database initializing
#~ `mysql -u root -p test_mysql < /home/mash/Progus/Practo/ActiveRecord/test_mysql.sql`
	class User < ActiveRecord::Base
		has_one :profile
		has_many :posts	
		has_and_belongs_to_many :clans
	end

	class Profile < ActiveRecord::Base
		belongs_to :user
	end

	class Post < ActiveRecord::Base
		belongs_to :user
	end

	class Clan < ActiveRecord::Base
		has_and_belongs_to_many :users
	end
	
	#~ puts("1")
#~ dano =  User.create(name: 'NanoDano')

#~ puts("2")
#~ # A few ways to create the profile for the user
#~ Profile.create(bio: "YOH! Nano Driver!", user: dano)
#~ dano.profile = Profile.create(bio: "YOH! Nano Climber!")
#~ dano.create_profile(bio: "YOH! My Nano Slinder!")
#~ puts("3")
#~ # A few ways to add a post to user (one-to-many relationship)
#~ dano.posts.create(content: "Whazzup! Driver!")
#~ dano.posts.append(Post.create(content: "Whazzup! SLinder!"))
#~ Post.create(content: "Whazzup! Climber!", user: dano)
#~ puts("4")
#~ # Create the clans & relationships (many-to-many relationships)
#~ dano.clans.create(name: "Belgian DIVRs'")
#~ dano.clans.append(Clan.create(name: "Belgian CLMBRs'"))
#~ Clan.create(name: "Belgian SLNDRs'", users: [dano])
#~ puts("5")
#~ # Pulling the related Objects

#~ u = User.find_by(name: "NanoDano")
#~ puts("6")
#~ puts u.inspect
#~ puts u.profile.inspect

#~ puts u.posts.inspect
#~ puts u.post_ids.inspect

#~ puts u.clans.inspect
#~ puts u.clan_ids.inspect
end

require 'irb'

include DBConnector
include Migrator
include TablesModels




def showManifesto(table_name)
	puts(table_name.to_s)
	#~ eval("#{table_name.to_s}").columns.each{|column| puts("#{column.name} :: #{column.type}")}
	eval(%{#{table_name.to_s}.columns.each{|column| puts("#%s{column.name} :: #%s{column.type}")}}%(["", ""]))
	puts()
end
connectDatabase()

showManifesto(:User)
showManifesto(:Profile)
showManifesto(:Post)
showManifesto(:Clan)



