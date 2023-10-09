
all:
	docker-compose -f ./srcs/docker-compose.yml up -d 

build:
	sh ./srcs/requirements/tools/make_dir.sh
	docker-compose -f ./srcs/docker-compose.yml up -d --build

no_cache:
	docker-compose -f ./srcs/docker-compose.yml build --no-cache
	sudo kill -9 $(sudo lsof -t -i:3306)
	docker-compose -f ./srcs/docker-compose.yml up -d

down:
	docker-compose -f ./srcs/docker-compose.yml down

re:
	docker-compose -f ./srcs/docker-compose.yml up -d --build

clean: down
	docker system prune -a

fclean:
	sudo rm -rf ../../data/
	docker stop $$(docker ps -qa)
	docker system prune --all --force --volumes
	docker network prune --force
	docker volume prune --force

#clean_eval:
# docker stop $(docker ps -qa);
# docker rm $(docker ps -qa);
# docker rmi -f $(docker images -qa);
# docker volume rm $(docker volume ls -q);
# docker network rm $(docker network ls -q) 2>/dev/null

logs:
	@echo ">> MariaDB:\n"
	docker logs mariadb
	@echo "\n"
	@echo ">> Nginx:\n"
	docker logs nginx
	docker exec -it nginx cat /var/log/nginx/error.log
	@echo "\n"
	@echo ">> Wordpress:\n"
	docker logs wordpress
	@echo "\n"

.PHONY: all build down re clean fclean logs no_cache